
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
%token COMMAND_SEPARATOR
%token VARIABLE_SEPARATOR


%%

program: 
         myProgram
        ;

myProgram:
		NAME_MAIN_FUNCTION  commandBlock
		;


/*
		Основа
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
		COMMAND_SEPARATOR /*  TODO : see Rule.txt */
		;
