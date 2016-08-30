
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

/* Need for grammar */
%token One_or_more_digits

%token COMMAND_SEPARATOR
%token VARIABLE_SEPARATOR

/* Text */
%token CHAR					/* Планируется добавить поддержку unicode , чтобы русские символы отображались */
%token STRING
/* Logic */
%token LOGIC


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
		START_BLOCK							{   fprintf_s(yyout, "START_BLOCK \n");   }
		commands
		END_BLOCK							{ 	fprintf_s(yyout, "END_BLOCK \n");
											 	fclose(yyout);
												return; } /* TODO : see need delete fclose()*/
		;


commands:
		command commands | /* nothing */
		;

command:
		Value COMMAND_SEPARATOR /*  TODO : see Rule.txt */
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

		Number | {   fprintf_s(yyout, "Number ");   }
		LOGIC | {   fprintf_s(yyout, "Bool ");   }
		CHAR | {   fprintf_s(yyout, "Char ");   }
		STRING {   fprintf_s(yyout, "String ");   }
		;

/*
////////////////////////////////////////////////////////////////////
//						Числа
////////////////////////////////////////////////////////////////////
*/
Number : Integer | Float ; /* TODO : неоднозначность */
Integer : Have_sign Digit_part;
Digit_part : DIGIT_ZERO | Combination_of_digits_without_zero;
Combination_of_digits_without_zero : 
									DIGIT_MORE_ZERO Not_digit_or_is_digit /* (DIGIT)* */
									;
Not_digit_or_is_digit : 
						DIGIT Not_digit_or_is_digit| 
						 /* nothing */
						;


Float : Integer Fractional_part  Have_or_not_exponent_part; /* ( Exponent_part )? */
Have_or_not_exponent_part : Exponent_part | /* nothing */ ;
Fractional_part : 
				'.' One_or_more_digits
				;

Exponent_part : Have_sign Exponent_symbol ;
Have_sign : "+" | "-" | /* nothing */ ;
Exponent_symbol : "e" | "E" ;
