
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
%token ADDRESED_OPERATION

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

%token NAME_TYPE

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
			Variable | Value
			;

Variable: 
		Identificator /*  TODO : see ADDRESED_OPERATION*/
		;
/*
////////////////////////////////////////////////////////////////////
//
//
// Комманды
// TODO : оператор присвоения
//
//
////////////////////////////////////////////////////////////////////
*/
Value:
		Literal {   fprintf_s(yyout, "Literal \n");   }
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

Literal :

		Number | 
		LOGIC |
		CHAR | 
		STRING
		;

/*
////////////////////////////////////////////////////////////////////
//						Числа
////////////////////////////////////////////////////////////////////
*/
Number : FLOAT | INT; /* TODO : неоднозначность */

