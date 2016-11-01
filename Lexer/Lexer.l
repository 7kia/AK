/* $Id: scanner.ll 44 2008-10-23 09:03:19Z tb $ -*- mode: c++ -*- */
/** \file scanner.ll Define the example Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
extern FILE *yyout;
FILE *yyOutId = nullptr;

#include "Grammar.h"
#include "scanner.h"

/* import the parser's token type into a local typedef */
typedef example::Parser::token token;
typedef example::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

using namespace std;

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "ExampleFlexLexer" */
%option prefix="Example"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput 

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
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
CHAR				\'.\'
STRING				\"(.)*\"

NAME_INTEGER		"int"
NAME_FLOAT			"float"
NAME_CHAR			"char"
NAME_STRING			"string"
NAME_LOGIC			"bool"

LOGIC				true|false

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


/*PREFIX_TYPE			{PREFIX_CONST}?(PREFIX_NUMERIC_TYPES)? */

/* DEFINITION_POINTER	((PREFIX_CONST)?STAR)?; */
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


%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}


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
{MULTI_STRING_COMMENT}	 
{
	fprintf_s(yyOutId, " Multi string comment \n");
    yylval->integerVal = atoi(yytext);
    return token::MULTI_STRING_COMMENT;
}

{ONLY_STRING_COMMENT}			{ fprintf_s(yyOutId, " Only string comment \n"); return ONLY_STRING_COMMENT; };


("main")						{ fprintf_s(yyOutId, " MAIN_FUNCTION "); return NAME_MAIN_FUNCTION; }

{START_BLOCK}					{ return START_BLOCK; }
{END_BLOCK}						{ return END_BLOCK; }

{INT}							{ fprintf_s(yyOutId, "Integer "); return INT; }
{FLOAT}							{ fprintf_s(yyOutId, "Float "); return FLOAT; }

{PLUS}							{ fprintf_s(yyOutId, "Plus "); return PLUS; }
{MINUS}							{ fprintf_s(yyOutId, "Minus "); return MINUS; }
{DIVIDE}						{ fprintf_s(yyOutId, "Divide "); return DIVIDE; }
{STAR}							{ fprintf_s(yyOutId, "Star "); return STAR; }
{PERCENT}						{ fprintf_s(yyOutId, "Percent "); return PERCENT; }

{LESS}							{ fprintf_s(yyOutId, "Less "); return LESS; }
{MORE}							{ fprintf_s(yyOutId, "More "); return MORE; }


{NEGATION}						{ fprintf_s(yyOutId, "Negation "); return NEGATION; }
{ASSIGN}						{ fprintf_s(yyOutId, "Assign "); return ASSIGN; }

{PLUS_ASSIGN}					{ fprintf_s(yyOutId, "+= "); return PLUS_ASSIGN; }
{MINUS_ASSIGN}					{ fprintf_s(yyOutId, "-= "); return MINUS_ASSIGN; }
{MULTIPLY_ASSIGN}				{ fprintf_s(yyOutId, "*= "); return MULTIPLY_ASSIGN; }
{DIVIDE_ASSIGN}					{ fprintf_s(yyOutId, "/= "); return DIVIDE_ASSIGN; }
{PERCENT_ASSIGN}				{ fprintf_s(yyOutId, "%= "); return PERCENT_ASSIGN; }

{AMPERSAND}						{ fprintf_s(yyOutId, "& "); return AMPERSAND; }

{LOGIC_AND}						{ fprintf_s(yyOutId, "&& "); return LOGIC_AND; }
{LOGIC_OR}						{ fprintf_s(yyOutId, "|| "); return LOGIC_OR; }
{LESS_EQUAL}					{ fprintf_s(yyOutId, "<= "); return LESS_EQUAL; }
{MORE_EQUAL}					{ fprintf_s(yyOutId, ">= "); return MORE_EQUAL; }

{EQUAL}							{ fprintf_s(yyOutId, "== "); return EQUAL; }
{NOT_EQUAL}						{ fprintf_s(yyOutId, "!= "); return NOT_EQUAL; }

";"								{ fprintf_s(yyOutId, "Command separator \n"); return COMMAND_SEPARATOR; }
","								{ fprintf_s(yyOutId, "Variable separator ");  return VARIABLE_SEPARATOR; }

{START_IDENTIFICATION}			{ fprintf_s(yyOutId, "[ ");  return START_IDENTIFICATION; }
{END_IDENTIFICATION}			{ fprintf_s(yyOutId, "] ");  return END_IDENTIFICATION; }


{CHAR}							{ fprintf_s(yyOutId, "Char "); return CHAR; }
{STRING}						{ fprintf_s(yyOutId, "String "); return STRING; }

{NAME_INTEGER}					{ fprintf_s(yyOutId, "int "); return NAME_INTEGER; }
{NAME_FLOAT}					{ fprintf_s(yyOutId, "float "); return NAME_FLOAT; }
{NAME_CHAR}						{ fprintf_s(yyOutId, "char "); return NAME_CHAR; }
{NAME_STRING}					{ fprintf_s(yyOutId, "string "); return NAME_STRING; }
{NAME_LOGIC}					{ fprintf_s(yyOutId, "bool "); return NAME_LOGIC; }

{LOGIC}							{ fprintf_s(yyOutId, "Bool ");   return LOGIC; }
{NAME_RETURN}					{ fprintf_s(yyOutId, " return ");   return NAME_RETURN; }

{PREFIX_SIGNED}					{ fprintf_s(yyOutId, "signed ");   return PREFIX_SIGNED; }
{PREFIX_UNSIGNED}				{ fprintf_s(yyOutId, "unsigned ");   return PREFIX_UNSIGNED; }
{PREFIX_LONG}					{ fprintf_s(yyOutId, "long ");   return PREFIX_LONG; }


{PREFIX_CONST}					{ fprintf_s(yyOutId, "const ");   return PREFIX_CONST; }

{IF_OPERATOR}					{ fprintf_s(yyOutId, "if ");   return IF_OPERATOR; }
{ELSE_OPERATOR}					{ fprintf_s(yyOutId, "else ");   return ELSE_OPERATOR; }
{SWITCH_OPERATOR}				{ fprintf_s(yyOutId, "switch ");   return SWITCH_OPERATOR; }
{CASE_OPERATOR}					{ fprintf_s(yyOutId, "case ");   return CASE_OPERATOR; }
{CASE_ENUMERATOR}				{ fprintf_s(yyOutId, " case_enumerator ");   return CASE_ENUMERATOR; }

{WHILE_OPERATOR}				{ fprintf_s(yyOutId, "while ");   return WHILE_OPERATOR; }
{DO_OPERATOR}					{ fprintf_s(yyOutId, "do ");   return DO_OPERATOR; }
{FOR_OPERATOR}					{ fprintf_s(yyOutId, "for ");   return FOR_OPERATOR; }
{BREAK_OPERATOR}				{ fprintf_s(yyOutId, "break ");   return BREAK_OPERATOR; }
{CONTINUE_OPERATOR}				{ fprintf_s(yyOutId, " continue ");   return CONTINUE_OPERATOR; }

{Identificator}					{ fprintf_s(yyOutId, "Identificator ");   return Identificator; }

{START_LIST_ARGUMENTS}			{ fprintf_s(yyOutId, "START_LIST_ARGUMENTS ");   return START_LIST_ARGUMENTS; }
{END_LIST_ARGUMENTS}			{ fprintf_s(yyOutId, "END_LIST_ARGUMENTS ");   return END_LIST_ARGUMENTS; }

([ \t\n]+)						/* skip */;

 /*** END EXAMPLE - Change the example lexer rules above ***/

%% 

/*
//
//
//
//Additional Code
//
//
//
*/

namespace example {

Scanner::Scanner(std::istream* in,
		 std::ostream* out)
    : ExampleFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}

/* This implementation of ExampleFlexLexer::yylex() is required to fill the
 * vtable of the class ExampleFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int ExampleFlexLexer::yylex()
{
    std::cerr << "in ExampleFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int ExampleFlexLexer::yywrap()
{
    return 1;
}
