%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;
#include "Lexer.h"
#include "Grammar.h"

%}

/*
////////////////////////////////////////////////////////////////////
//
//
//		Основа
//
//
////////////////////////////////////////////////////////////////////
*/
START_BLOCK				"{"
END_BLOCK				"}"


/*
////////////////////////////////////////////////////////////////////
//
//
//		Алфавит
//
//
////////////////////////////////////////////////////////////////////
*/

/*
////////////////////////////////////////////////////////////////////
//
//		Цифры
//
////////////////////////////////////////////////////////////////////
*/
DIGIT_MORE_ZERO			([1-9]) /* TODO : see need these + */
DIGIT_ZERO				"0"
DIGIT					([0-9])

/* Need for grammar */
Have_sign				("+"|"-")?
INT						{Have_sign}([0-9]+)
Expotential_part		{Have_sign}("e"|"E"){INT}
FLOAT					{Have_sign}((([0-9]+)"."([0-9]*))|("."([0-9]+))){Expotential_part}?

/*
//////////////////////////////
//			Операции
//////////////////////////////
*/

PLUS					"+"
MINUS					"-"
DIVIDE					"/"
STAR					"*"

ASSIGN					"="		

REFERENCE				"&"
/*
//////////////////////////////
//		Разделители
//////////////////////////////
*/
COMMAND_SEPARATOR		";"
VARIABLE_SEPARATOR		","

/**/
/*
//////////////////////////////
//		Типы и их имена
//////////////////////////////
*/
CHAR					\'.\'
STRING					\"(.)*\"

NAME_INTEGER		"int"
NAME_FLOAT			"float"
NAME_CHAR			"char"
NAME_STRING			"string"
NAME_LOGIC			"bool"

NAME_TYPE			(NAME_INTEGER)|(NAME_FLOAT)|(NAME_CHAR)|(NAME_STRING)|(NAME_LOGIC)


LOGIC					true|false

/* Identificator and it used */
Identificator			[a-zA-Z_][a-zA-Z0-9_]*
ARRAY_ELEMENT			{Identificator}("["INT"]")+

/* TODO : not work */
ADDRESED_OPERATION		({STAR}|{REFERENCE})* 
/**/

START_LIST_ARGUMENTS	"("
END_LIST_ARGUMENTS		")"
CASE_ENUMERATOR			":"
UNDERSCORE_SYMBOL		"_"

%%

("main")       { return NAME_MAIN_FUNCTION;  }

"{"				{ return START_BLOCK; }
"}"				{ return END_BLOCK; }

{INT}			{ fprintf_s(yyout, "Integer "); return INT; }
{FLOAT}			{ fprintf_s(yyout, "Float "); return FLOAT; }

{PLUS}			{ fprintf_s(yyout, "Plus "); return PLUS; }
{MINUS}			{ fprintf_s(yyout, "Minus "); return MINUS; }
{DIVIDE}		{ fprintf_s(yyout, "Divide "); return DIVIDE; }
{STAR}			{ fprintf_s(yyout, "Star "); return STAR; }

";"				{ fprintf_s(yyout, "Command separator "); return COMMAND_SEPARATOR; }
","				{ fprintf_s(yyout, "Variable separator ");  return VARIABLE_SEPARATOR; }

{CHAR}			{ fprintf_s(yyout, "Char "); return CHAR; }
{STRING}		{ fprintf_s(yyout, "String "); return STRING; }

{NAME_INTEGER}		{ fprintf_s(yyout, "int "); return NAME_INTEGER; }
{NAME_FLOAT}		{ fprintf_s(yyout, "float "); return NAME_FLOAT; }
{NAME_CHAR}			{ fprintf_s(yyout, "char "); return NAME_CHAR; }
{NAME_STRING}		{ fprintf_s(yyout, "string "); return NAME_STRING; }
{NAME_LOGIC}		{ fprintf_s(yyout, "bool "); return NAME_LOGIC; }

{NAME_TYPE}		{ fprintf_s(yyout, "Name type - "); return NAME_TYPE; }

{LOGIC}			{ fprintf_s(yyout, "Bool ");   return LOGIC; }

{Identificator}			{ fprintf_s(yyout, "Identificator ");   return Identificator; }
{ARRAY_ELEMENT}			{ fprintf_s(yyout, "Array element ");   return ARRAY_ELEMENT; }
{ADDRESED_OPERATION}	{ fprintf_s(yyout, "Addressed operations ");   return ADDRESED_OPERATION; }

("tchau"|"bye")"\n"   { return BYE; }
.                     { yyerror();  }

%%

void ParseFile(const char* inputFileName, const char* outputFileName)
{
	fopen_s(&yyout, outputFileName, "w");

	fopen_s(&yyin, inputFileName, "r");
	yyparse();

	fclose(yyin);
	fclose(yyout);
}

int main(void)
{
	//ParseFile("text1.txt", "out1.txt");
	//ParseFile("Literal1.txt", "outLiteral1.txt");

	//ParseFile("Tests\\Identifier.txt", "Tests\\Output\\OutputIdentifier.txt");
	//ParseFile("Tests\\Types.txt", "Tests\\Output\\OutputTypes.txt");

	ParseFile("Tests\\Syntax\\Numbers.txt", "Tests\\OutputSyntax\\OutputNumbers.txt");
}


int yywrap(void)
{
   return 0;
}

int yyerror(void)
{
    fprintf_s(yyout, "Error\n");
}
