
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
%token PERCENT

%token LESS
%token MORE


%token ASSIGN
/* Need for grammar */
%token Have_sign

%token REFERENCE

%token COMMAND_SEPARATOR
%token VARIABLE_SEPARATOR

/*
//////////////////////////////
//		Типы и их имена
//////////////////////////////
*/
/* Text */
%token CHAR					/* Планируется добавить поддержку unicode , чтобы русские символы отображались */
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

%token WHILE_OPERATOR
%token DO_OPERATOR
%token FOR_OPERATOR
%token BREAK_OPERATOR
%token CONTINUE_OPERATOR

%token LOGIC
%token NAME_RETURN

%token Identificator
%token ARRAY_ELEMENT

%token START_LIST_ARGUMENTS
%token END_LIST_ARGUMENTS

/* 
	%left, %right, %nonassoc и %precedence управляют разрешением
	приоритета операторов и правил ассоциативности
*/



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
//		Основа
//
//
////////////////////////////////////////////////////////////////////
*/
commandBlock:
		START_BLOCK							{   fprintf_s(yyout, "\n==Start block code==\n");   }
		commands
		END_BLOCK							{ 	fprintf_s(yyout, "==End block code==\n"); } /* TODO : see need delete fclose()*/
		;


commands:
		command commands | /* nothing */
		;

command:
		commandContent COMMAND_SEPARATOR /*  TODO : see Rule.txt */
		;

commandContent:
			Expression | Assign_for_variable |  Any_branching | Any_loop | Any_interrupt_operator | Return_function
			;

Variable: 
		Identificator /*  TODO : see ADDRESED_OPERATION*/
		;

		/*
////////////////////////////////////////////////////////////////////
//
//
//						Типы
//
//
////////////////////////////////////////////////////////////////////
*/

NAME_TYPE	:
		NAME_CHAR | NAME_STRING | NAME_LOGIC
		;

NAME_NUMERIC_TYPES :
		NAME_INTEGER | NAME_FLOAT /* TODO : see need there char */
		;

Literal :

		Number | 
		LOGIC |
		CHAR | 
		STRING
		;

PREFIX_TYPE	: Can_have_const Name_without_const ;
Can_have_const :  /* nothing */ | PREFIX_CONST ;
Name_without_const :  NAME_TYPE | PREFIX_NUMERIC_TYPES Can_be_long NAME_NUMERIC_TYPES;
PREFIX_NUMERIC_TYPES	:  PREFIX_SIGNED | PREFIX_UNSIGNED ;
Can_be_long : /* nothing */ | PREFIX_LONG;

DEFINITION_POINTER	: /* nothing */ | Can_have_const STAR ;

/*
////////////////////////////////////////////////////////////////////
//						Числа
////////////////////////////////////////////////////////////////////
*/
Number : FLOAT | INT; /* TODO : неоднозначность */
/*
////////////////////////////////////////////////////////////////////
//						Выражения
////////////////////////////////////////////////////////////////////
*/
Expression : Arithmetic_expression | Bool_expression ; /* | bool_expression*/

Arithmetic_signs : PLUS | MINUS | STAR | DIVIDE | PERCENT ;
Arithmetic_expression : Value Right_arithmetic_expression_part ;

Right_arithmetic_expression_part : /* nothing */ | Arithmetic_signs Arithmetic_expression ;


Bool_signs : LESS | MORE ;
Bool_expression : Value Right_bool_expression_part;
/*
				| bool_expression '<' Value | bool_expression LESSOREQUALS Value
				| bool_expression '>' Value | bool_expression MOREOREQUALS Value
				| bool_expression EQUALS Value | bool_expression NOTEQUALS Value
				| bool_expression AND Value | bool_expression OR Value
				| '!' bool_expression

*/

Right_bool_expression_part : /* nothing */ | Bool_signs Bool_expression ;

/*
////////////////////////////////////////////////////////////////////
//
//
// Комманды
//
//
////////////////////////////////////////////////////////////////////
*/

Value:
		Call_function | Variable  | Literal /* TODO : add <Call function> | <variable>   | <expression> | */
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
					DEFINITION_POINTER  
					;
/*
////////////////////////////////////////////////////////////////////
//
//
// Функции
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
// Условия
//
////////////////////////////////////////////////////////////////////
*/
Any_branching : Usual_branching | Switch_branching;

/* TODO : переделать "(" <expression<bool>> ")" */ 
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

// /\ должна ли быть именно *в Switch_block, то есть может ли switch быть пустым

/*
////////////////////////////////////////////////////////////////////
//
// Циклы
//
////////////////////////////////////////////////////////////////////
*/
Any_loop : Loop_with_precondition | Loop_with_postcondition | Loop_with_counter;
// TODO : переделать "(" <expression<bool>> ")"
Loop_with_precondition :  WHILE_OPERATOR Condition_part commandBlock;
Condition_part :  START_LIST_ARGUMENTS Value END_LIST_ARGUMENTS; /* TODO : see correctness, was <expression<bool>> instead Value */

Loop_with_postcondition :  DO_OPERATOR commandBlock WHILE_OPERATOR Condition_part ;

Loop_with_counter :   FOR_OPERATOR  START_LIST_ARGUMENTS  Parameters_for END_LIST_ARGUMENTS   commandBlock;

Parameters_for :  Start_value_for COMMAND_SEPARATOR Condition_end_for COMMAND_SEPARATOR Next_value_counter;
Start_value_for :  Assign_for_variable ;/* TODO : see can replace on Assign_for_variable */
Condition_end_for :  Value; /* TODO : see correctness */
Next_value_counter :  Value; /* TODO : see correctness */


Any_interrupt_operator :  CONTINUE_OPERATOR  | BREAK_OPERATOR ; 
/*
<reserve loop literal> :  WHILE_OPERATOR | DO_OPERATOR | FOR_OPERATOR | CONTINUE_OPERATOR |  BREAK_OPERATOR ;
*/

/*
///////////////////////////
// Список значении для вызовов функции
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
// Список значении для вызовов функции
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