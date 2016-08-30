
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

/* Need for grammar */
%token Have_sign

%token COMMAND_SEPARATOR
%token VARIABLE_SEPARATOR

/* Text */
%token CHAR					/* ����������� �������� ��������� unicode , ����� ������� ������� ������������ */
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
//		������
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
		Value COMMAND_SEPARATOR /*  TODO : see Rule.txt */
		;

/*
////////////////////////////////////////////////////////////////////
//
//
// ��������
// TODO : �������� ����������
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
//						����
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
//						�����
////////////////////////////////////////////////////////////////////
*/
Number : INT | FLOAT; /* TODO : ��������������� */

