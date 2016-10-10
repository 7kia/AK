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
DIVIDE					" /"
STAR					"*"
PERCENT					"%"

LESS					"<"
MORE					">"
NEGATION				"!"
ASSIGN					"="		

AMPERSAND				"&"
/*
//			Двухсимвольные
*/
PLUS_ASSIGN				"+="
MINUS_ASSIGN			"-="
MULTIPLY_ASSIGN			"*="
DIVIDE_ASSIGN			"/="
PERCENT_ASSIGN			"%="

/*
//			Битовые
//  TODO : отсутствуют
*/
BIT_AND					"&"
BIT_OR					"|"
BIT_XOR					"^"
BIT_LEFT_SHIFT			"<<"
BIT_RIGHT_SHIFT			">>"

BIT_AND_ASSIGN			"&="
BIT_OR_ASSIGN			"|="
BIT_XOR_ASSIGN			"^="
BIT_LEFT_SHIFT_ASSIGN	"<<="
BIT_RIGHT_SHIFT_ASSIGN	">>="

INCREMENT				"++"
DECREMENT				"--"

/*
//			Логические(кроме НЕ)
*/
LOGIC_AND				"&&"
LOGIC_OR				"||"
LESS_EQUAL				"<="
MORE_EQUAL				">="

EQUAL					"=="
NOT_EQUAL				"!="
/*
//////////////////////////////
//		Разделители
//////////////////////////////
*/
COMMAND_SEPARATOR		";"
VARIABLE_SEPARATOR		","

START_IDENTIFICATION	"["
END_IDENTIFICATION		"]"

/*
//		Комментарии
*/
START_ONE_STRING_COMMENT "//"
START_MULTI_STRING_COMMENT "\*"
END_MULTI_STRING_COMMENT "*/"

ONLY_STRING_COMMENT		{START_ONE_STRING_COMMENT}[.]*"\n"
MULTI_STRING_COMMENT	{START_MULTI_STRING_COMMENT}(.)*|[\n]*{END_MULTI_STRING_COMMENT}
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

LOGIC					true|false

NAME_RETURN			"return"
/*
//////////////////////////////
//		Префиксы типов
//////////////////////////////
*/

PREFIX_SIGNED			"signed"
PREFIX_UNSIGNED			"unsigned"
PREFIX_LONG				"long"

PREFIX_CONST			"const"


/*PREFIX_TYPE				{PREFIX_CONST}?(PREFIX_NUMERIC_TYPES)? */

/* DEFINITION_POINTER		((PREFIX_CONST)?STAR)?; */
/*
////////////////////////////////////////////////////////////////////
//
// Условия
//
////////////////////////////////////////////////////////////////////
*/

IF_OPERATOR				"if"
ELSE_OPERATOR			"else"
SWITCH_OPERATOR			"switch"
CASE_OPERATOR			"case"
/*
////////////////////////////////////////////////////////////////////
//
// Циклы
//
////////////////////////////////////////////////////////////////////
*/

WHILE_OPERATOR			"while"
DO_OPERATOR				"do"
FOR_OPERATOR			"for"
BREAK_OPERATOR			"break"
CONTINUE_OPERATOR		"continue"

/*
////////////////////////////////////////////////////////////////////
//
//
//						Типы
//
//
////////////////////////////////////////////////////////////////////
*/

/*
////////////////////////////////////////////////////////////////////
//
//
// Комманды
//
//
////////////////////////////////////////////////////////////////////
*/

/*
//////////////////////////////////
//		Объявление указателя
//////////////////////////////////
*/
/* Identificator and it used */
Identificator			[a-zA-Z_][a-zA-Z0-9_]*

/* TODO : not work */
/* .                     { yyerror();  }
*/
/*  ADDRESED_OPERATION		({STAR}|{AMPERSAND})* */

START_LIST_ARGUMENTS	"("
END_LIST_ARGUMENTS		")"
CASE_ENUMERATOR			":"
UNDERSCORE_SYMBOL		"_"

%%
{MULTI_STRING_COMMENT}				{ fprintf_s(yyout, " Multi string comment \n"); return MULTI_STRING_COMMENT; };
{ONLY_STRING_COMMENT}				{ fprintf_s(yyout, " Only string comment \n"); return ONLY_STRING_COMMENT; };


("main")		{ fprintf_s(yyout, " MAIN_FUNCTION "); return NAME_MAIN_FUNCTION; }

{START_BLOCK}	{ return START_BLOCK; }
{END_BLOCK}		{ return END_BLOCK; }

{INT}			{ fprintf_s(yyout, "Integer "); return INT; }
{FLOAT}			{ fprintf_s(yyout, "Float "); return FLOAT; }

{PLUS}			{ fprintf_s(yyout, "Plus "); return PLUS; }
{MINUS}			{ fprintf_s(yyout, "Minus "); return MINUS; }
{DIVIDE}		{ fprintf_s(yyout, "Divide "); return DIVIDE; }
{STAR}			{ fprintf_s(yyout, "Star "); return STAR; }
{PERCENT}		{ fprintf_s(yyout, "Percent "); return PERCENT; }

{LESS}			{ fprintf_s(yyout, "Less "); return LESS; }
{MORE}			{ fprintf_s(yyout, "More "); return MORE; }


{NEGATION}		{ fprintf_s(yyout, "Negation "); return NEGATION; }
{ASSIGN}		{ fprintf_s(yyout, "Assign "); return ASSIGN; }

{PLUS_ASSIGN}		{ fprintf_s(yyout, "+= "); return PLUS_ASSIGN; }
{MINUS_ASSIGN}		{ fprintf_s(yyout, "-= "); return MINUS_ASSIGN; }
{MULTIPLY_ASSIGN}		{ fprintf_s(yyout, "*= "); return MULTIPLY_ASSIGN; }
{DIVIDE_ASSIGN}		{ fprintf_s(yyout, "/= "); return DIVIDE_ASSIGN; }
{PERCENT_ASSIGN}		{ fprintf_s(yyout, "%= "); return PERCENT_ASSIGN; }

{AMPERSAND}				{ fprintf_s(yyout, "& "); return AMPERSAND; }

{LOGIC_AND}		{ fprintf_s(yyout, "&& "); return LOGIC_AND; }
{LOGIC_OR}		{ fprintf_s(yyout, "|| "); return LOGIC_OR; }
{LESS_EQUAL}		{ fprintf_s(yyout, "<= "); return LESS_EQUAL; }
{MORE_EQUAL}		{ fprintf_s(yyout, ">= "); return MORE_EQUAL; }

{EQUAL}					{ fprintf_s(yyout, "== "); return EQUAL; }
{NOT_EQUAL}				{ fprintf_s(yyout, "!= "); return NOT_EQUAL; }

";"				{ fprintf_s(yyout, "Command separator \n"); return COMMAND_SEPARATOR; }
","				{ fprintf_s(yyout, "Variable separator ");  return VARIABLE_SEPARATOR; }

{START_IDENTIFICATION}			{ fprintf_s(yyout, "[ ");  return START_IDENTIFICATION; }
{END_IDENTIFICATION}			{ fprintf_s(yyout, "] ");  return END_IDENTIFICATION; }


{CHAR}			{ fprintf_s(yyout, "Char "); return CHAR; }
{STRING}		{ fprintf_s(yyout, "String "); return STRING; }

{NAME_INTEGER}		{ fprintf_s(yyout, "int "); return NAME_INTEGER; }
{NAME_FLOAT}		{ fprintf_s(yyout, "float "); return NAME_FLOAT; }
{NAME_CHAR}			{ fprintf_s(yyout, "char "); return NAME_CHAR; }
{NAME_STRING}		{ fprintf_s(yyout, "string "); return NAME_STRING; }
{NAME_LOGIC}		{ fprintf_s(yyout, "bool "); return NAME_LOGIC; }

{LOGIC}				{ fprintf_s(yyout, "Bool ");   return LOGIC; }
{NAME_RETURN}		{ fprintf_s(yyout, " return ");   return NAME_RETURN; }

{PREFIX_SIGNED}			{ fprintf_s(yyout, "signed ");   return PREFIX_SIGNED; }
{PREFIX_UNSIGNED}		{ fprintf_s(yyout, "unsigned ");   return PREFIX_UNSIGNED; }
{PREFIX_LONG}			{ fprintf_s(yyout, "long ");   return PREFIX_LONG; }


{PREFIX_CONST}					{ fprintf_s(yyout, "const ");   return PREFIX_CONST; }

{IF_OPERATOR}					{ fprintf_s(yyout, "if ");   return IF_OPERATOR; }
{ELSE_OPERATOR}					{ fprintf_s(yyout, "else ");   return ELSE_OPERATOR; }
{SWITCH_OPERATOR}				{ fprintf_s(yyout, "switch ");   return SWITCH_OPERATOR; }
{CASE_OPERATOR}					{ fprintf_s(yyout, "case ");   return CASE_OPERATOR; }
{CASE_ENUMERATOR}					{ fprintf_s(yyout, " case_enumerator ");   return CASE_ENUMERATOR; }

{WHILE_OPERATOR}				{ fprintf_s(yyout, "while ");   return WHILE_OPERATOR; }
{DO_OPERATOR}					{ fprintf_s(yyout, "do ");   return DO_OPERATOR; }
{FOR_OPERATOR}					{ fprintf_s(yyout, "for ");   return FOR_OPERATOR; }
{BREAK_OPERATOR}				{ fprintf_s(yyout, "break ");   return BREAK_OPERATOR; }
{CONTINUE_OPERATOR}				{ fprintf_s(yyout, " continue ");   return CONTINUE_OPERATOR; }

{Identificator}					{ fprintf_s(yyout, "Identificator ");   return Identificator; }

{START_LIST_ARGUMENTS}			{ fprintf_s(yyout, "START_LIST_ARGUMENTS ");   return START_LIST_ARGUMENTS; }
{END_LIST_ARGUMENTS}			{ fprintf_s(yyout, "END_LIST_ARGUMENTS ");   return END_LIST_ARGUMENTS; }

("tchau"|"bye")"\n"   { return BYE; /* TODO : delete */}

([ \t\n]+)	/* skip */;


%%

void ParseFile(const char* inputFileName, const char* outputFileName)
{
	fopen_s(&yyout, outputFileName, "w");

	fopen_s(&yyin, inputFileName, "r");
	yyparse();

	fclose(yyin);
	fclose(yyout);
}

static const int AMOUNT_ARGUMENTS = 3;


int main(int argc, char *argv[])
{

	if (argc != AMOUNT_ARGUMENTS)
	{
		return 1;
	}
	//ParseFile("text1.txt", "out1.txt");
	//ParseFile("Literal1.txt", "outLiteral1.txt");

	//ParseFile("Tests\\Identifier.txt", "Tests\\Output\\OutputIdentifier.txt");
	//ParseFile("Tests\\Types.txt", "Tests\\Output\\OutputTypes.txt");
	//ParseFile("Tests\\Functions.txt", "Tests\\Output\\OutputFunctions.txt");
	//ParseFile("Tests\\Conditions.txt", "Tests\\Output\\OutputConditions.txt");

	//ParseFile("Tests\\Syntax\\Numbers.txt", "Tests\\OutputSyntax\\OutputNumbers.txt");
	//ParseFile("Tests\\Syntax\\Loops.txt", "Tests\\OutputSyntax\\OutputLoops.txt");
	ParseFile(argv[1], argv[2]);

	return 0;
}


int yywrap(void)
{
   return 0;
}

void yyerror (const char *s)  /* вызывается yyparse в случае ошибки */
{
    fprintf_s(yyout, s);
}