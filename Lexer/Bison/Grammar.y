
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;

%}

%token NAME_MAIN_FUNCTION "Function main"
%token BYE

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

%token PREFIX_NUMERIC_TYPES
%token PREFIX_CONST

%token LOGIC

%token Identificator
%token ARRAY_ELEMENT
%%

program: 
         myProgram
        ;

myProgram:
		NAME_MAIN_FUNCTION  commandBlock
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
		START_BLOCK							{   fprintf_s(yyout, "Start main() \n");   }
		commands
		END_BLOCK							{ 	fprintf_s(yyout, "End main() \n");
											 	fclose(yyout);
												return; } /* TODO : see need delete fclose()*/
		;


commands:
		command commands | /* nothing */
		;

command:
		commandContent COMMAND_SEPARATOR /*  TODO : see Rule.txt */
		;

commandContent:
			Assign_for_variable | Variable | Value
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
		NAME_INTEGER | NAME_FLOAT | NAME_CHAR | NAME_STRING | NAME_LOGIC { fprintf_s(yyout, "Name type - "); }
		;


Literal :

		Number | 
		LOGIC |
		CHAR | 
		STRING
		;

PREFIX_TYPE	: Can_have_const Can_have_numeric_prefix ;
Can_have_const :  /* nothing */ | PREFIX_CONST ;
Can_have_numeric_prefix :  /* nothing */ | PREFIX_NUMERIC_TYPES ;
 
DEFINITION_POINTER	: /* nothing */ | Can_have_const STAR ;

/*
////////////////////////////////////////////////////////////////////
//						Числа
////////////////////////////////////////////////////////////////////
*/
Number : FLOAT | INT; /* TODO : неоднозначность */
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
		Literal {   fprintf_s(yyout, "Literal \n");   } /* TODO : add <Call function> | <variable>   | <expression> | */
	;

Assign_for_variable:
					Left_part_assign {   fprintf_s(yyout, "Left_part_assign \n"); }
					ASSIGN  {   fprintf_s(yyout, "it assign \n");   }
					Right_part_assign  {   fprintf_s(yyout, "Right_part_assign \n");   }/* TODO : add  */
					;

/*----------------------------*/
List_values		: 
				START_BLOCK Value_in_list Another_values_in_list END_BLOCK
				;

Value_in_list	:	List_values | Value ;
Another_values_in_list	:
						VARIABLE_SEPARATOR Value_in_list | /* nothing */
						;

Left_part_assign: Init_variable ;
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

