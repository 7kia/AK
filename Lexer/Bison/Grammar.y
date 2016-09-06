
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;

%}

%token BYE
%token NAME_MAIN_FUNCTION

%token START_BLOCK
%token END_BLOCK

%token DIGIT_MORE_ZERO			/* TODO : see need these + */
%token DIGIT_ZERO				
%token DIGIT					

%token INT
%token FLOAT

%token PLUS
%token MINUS
%token DIVIDE
%token STAR

%token ASSIGN
/* Need for grammar */
%token Have_sign

%token REFERENCE

%token COMMAND_SEPARATOR
%token VARIABLE_SEPARATOR

/*
//////////////////////////////
//		���� � �� �����
//////////////////////////////
*/
/* Text */
%token CHAR					/* ����������� �������� ��������� unicode , ����� ������� ������� ������������ */
%token STRING

%token NAME_INTEGER
%token NAME_FLOAT
%token NAME_CHAR
%token NAME_STRING
%token NAME_LOGIC

%token PREFIX_SIGNED
%token PREFIX_UNSIGNED
%token PREFIX_LONG

%token PREFIX_CONST

%token IF_OPERATOR
%token ELSE_OPERATOR
%token SWITCH_OPERATOR
%token CASE_OPERATOR
%token CASE_ENUMERATOR

%token LOGIC
%token NAME_RETURN

%token Identificator
%token ARRAY_ELEMENT

%token START_LIST_ARGUMENTS
%token END_LIST_ARGUMENTS

%%

program: 
        Function_block {	fclose(yyout);
												return;
												}
        ;


/*
////////////////////////////////////////////////////////////////////
//
//
//		������
//
//
////////////////////////////////////////////////////////////////////
*/
commandBlock:
		START_BLOCK							{   fprintf_s(yyout, "\n Start block code \n");   }
		commands
		END_BLOCK							{ 	fprintf_s(yyout, "\n End block code \n"); } /* TODO : see need delete fclose()*/
		;


commands:
		command commands | /* nothing */
		;

command:
		commandContent COMMAND_SEPARATOR /*  TODO : see Rule.txt */
		;

commandContent:
			Assign_for_variable | Value | Any_branching | Return_function
			;

Variable: 
		Identificator /*  TODO : see ADDRESED_OPERATION*/
		;

		/*
////////////////////////////////////////////////////////////////////
//
//
//						����
//
//
////////////////////////////////////////////////////////////////////
*/

NAME_TYPE	:
		NAME_INTEGER | NAME_FLOAT | NAME_CHAR | NAME_STRING | NAME_LOGIC
		;


Literal :

		Number | 
		LOGIC |
		CHAR | 
		STRING
		;

PREFIX_TYPE	: Can_have_const Can_have_numeric_prefix ;
Can_have_const :  /* nothing */ | PREFIX_CONST ;
Can_have_numeric_prefix :  /* nothing */ | PREFIX_NUMERIC_TYPES;
PREFIX_NUMERIC_TYPES	:  PREFIX_SIGNED | PREFIX_UNSIGNED | PREFIX_LONG ;

DEFINITION_POINTER	: /* nothing */ | Can_have_const STAR ;

/*
////////////////////////////////////////////////////////////////////
//						�����
////////////////////////////////////////////////////////////////////
*/
Number : FLOAT | INT; /* TODO : ��������������� */
/*
////////////////////////////////////////////////////////////////////
//
//
// ��������
//
//
////////////////////////////////////////////////////////////////////
*/

Value:
		Call_function | Variable | Literal /* TODO : add <Call function> | <variable>   | <expression> | */
	;

Assign_for_variable:
					Left_part_assign ASSIGN Right_part_assign /* TODO : add  */
					;

/*----------------------------*/
List_values		: 
				START_BLOCK Value_in_list Another_values_in_list END_BLOCK
				;

Value_in_list	:	List_values | Value ;
Another_values_in_list	:
						VARIABLE_SEPARATOR Value_in_list | /* nothing */
						;

Left_part_assign: Init_variable | Variable ;
Right_part_assign: Value | List_values ;
/*----------------------------*/

Init_variable:
				 Type_initialization Name_init_variable
				 ; /* instead " " <common separator> */


Name_init_variable: ARRAY_ELEMENT | Variable ;
/*                     		\/ Types.txt		*/

Type_initialization :
					PREFIX_TYPE  
					NAME_TYPE  
					DEFINITION_POINTER  
					;
/*
////////////////////////////////////////////////////////////////////
//
//
// �������
//
//
////////////////////////////////////////////////////////////////////
*/
Function_imp_or_init : Function_implementation | Function_init;

Function_init : 
				Type_initialization Function_name List_arguments/* TODO : add separator */
				;
Function_main : 
				Type_initialization NAME_MAIN_FUNCTION List_arguments commandBlock 
				{	
				 	fprintf_s(yyout, "\n End main() \n");
					fclose(yyout);
					return;
				}
				/* TODO : add separator */
				;

/* Three low string equal (<function implementation> | <function init>)+*/
Function_block : 
				Definition_function Other_function_imp_or_init;
				; 
Definition_function : Function_imp_or_init COMMAND_SEPARATOR;
Other_function_imp_or_init : Definition_function Other_function_imp_or_init | /* nothing */;

Function_name : Identificator ;
/*
////////////////////////////////////////////////////////////////////
//
// �������
//
////////////////////////////////////////////////////////////////////
*/
Any_branching : Usual_branching | Switch_branching;

/* TODO : ���������� "(" <expression<bool>> ")" */ 
Usual_branching : IF_OPERATOR Condition_part commandBlock Can_have_else_part ;

Condition_part: List_values ;
Can_have_else_part : /* nothing */ | Else_part;
Else_part : ELSE_OPERATOR Else_content ;
Else_content : Usual_branching | commandBlock Can_have_else_part;

Switch_branching : SWITCH_OPERATOR Check_value Switch_block ;
Check_value : START_LIST_ARGUMENTS Value END_LIST_ARGUMENTS; 

Switch_block : START_BLOCK Body_switch END_BLOCK;
Body_switch : /* nothing */ | Sequence_cases commandBlock Body_switch; /* (<all>)* */
Sequence_cases : Case_sequence Other_sequence_cases ;/* (<all>)+ */
Other_sequence_cases : Case_sequence Other_sequence_cases | /* nothing */ ; 
Case_sequence : CASE_OPERATOR Value CASE_ENUMERATOR;

// /\ ������ �� ���� ������ *� Switch_block, �� ���� ����� �� switch ���� ������


/*
///////////////////////////
// ������ �������� ��� ������� �������
///////////////////////////
*/
List_values : 
				START_LIST_ARGUMENTS Set_values END_LIST_ARGUMENTS
				;
/* Two low string equal Value  (VARIABLE_SEPARATOR Value )?*/
Set_values : Value Other_values | /* nothing */;
Other_values : VARIABLE_SEPARATOR Value Other_values | /* nothing */;
/*
///////////////////////////
// ������ �������� ��� ������� �������
///////////////////////////
*/
List_arguments : 
				START_LIST_ARGUMENTS Set_arguments END_LIST_ARGUMENTS
				;
/* Two low string equal Value  (VARIABLE_SEPARATOR Value )?*/
Set_arguments : Init_variable Other_arguments | /* nothing */;
Other_arguments : VARIABLE_SEPARATOR Init_variable Other_arguments | /* nothing */;

Call_function : Function_name List_values; 

Function_implementation : Function_main | Function_init commandBlock ;

Return_function : NAME_RETURN Value;