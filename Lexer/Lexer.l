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

/* Flex Declarations and Options ***/

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
// ////////////////////////////
//		Разделители
// ////////////////////////////
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

ONLY_STRING_COMMENT		{START_ONE_STRING_COMMENT}(.)*[\n]?
MULTI_STRING_COMMENT	{START_MULTI_STRING_COMMENT}((.)*|[\n]*){END_MULTI_STRING_COMMENT}
/* */
/*  Типы и их имена  */
CHAR				\'.\'
STRING				\"(.)*\"

NAME_INTEGER		"int"
NAME_FLOAT			"float"
NAME_CHAR			"char"
NAME_STRING			"string"
NAME_LOGIC			"bool"

LOGIC				true|false

NAME_RETURN			"return"

PREFIX_SIGNED			"signed"
PREFIX_UNSIGNED			"unsigned"
PREFIX_LONG				"long"

PREFIX_CONST			"const"


IF_OPERATOR				"if"
ELSE_OPERATOR			"else"
SWITCH_OPERATOR			"switch"
CASE_OPERATOR			"case"
/*
// //////////////////////////////////////////////////////////////////
//
// Циклы
//
// //////////////////////////////////////////////////////////////////
*/

WHILE_OPERATOR			"while"
DO_OPERATOR				"do"
FOR_OPERATOR			"for"
BREAK_OPERATOR			"break"
CONTINUE_OPERATOR		"continue"

/*
// //////////////////////////////////////////////////////////////////
//
//
//						Типы
//
//
// //////////////////////////////////////////////////////////////////
*/

/*
// //////////////////////////////////////////////////////////////////
//
//
// Комманды
//
//
// //////////////////////////////////////////////////////////////////
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


/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}


%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

 /*** BEGIN EXAMPLE - Change the example lexer rules below ***/

 	/*
{ONLY_STRING_COMMENT}
{
	/*
	fprintf_s(yyOutId, " Only string comment \n");
	TODO : rewrite
	*/
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::ONLY_STRING_COMMENT;
}
	*/
{MULTI_STRING_COMMENT}	 {
	/*
	fprintf(yyOutId, " Multi string comment \n");
	*/
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::MULTI_STRING_COMMENT;
}



"main" {
	/*
	fprintf_s(yyOutId, " MAIN_FUNCTION ");
	*/
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::NAME_MAIN_FUNCTION;
}

{START_BLOCK} {
	/*
	fprintf_s(yyOutId, "\n==Start block code==\n");
	*/
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::START_BLOCK;
}
{END_BLOCK} {
	/*
	fprintf_s(yyOutId, "==End block code==\n");
	*/
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::END_BLOCK;
}

{INT} {
	/*
	fprintf_s(yyOutId, "Integer ");

	*/
    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::INT;
}
{FLOAT} {
	/*
	fprintf_s(yyOutId, "Float ");

	*/
    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::FLOAT;
}

{PLUS} {
	/*
	fprintf_s(yyOutId, "Plus ");

	*/
    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::PLUS;
}
{MINUS} {
	
		/*
	fprintf_s(yyOutId, "Plus ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::PLUS;
}
{DIVIDE} {
		/*
	fprintf_s(yyOutId, "Divide ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::DIVIDE;
}
{STAR} {
		/*
	fprintf_s(yyOutId, "Star ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::STAR;
}
{PERCENT} {
	/*
	fprintf_s(yyOutId, "Percent ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::PERCENT;
}
{LESS} {
	/*
	fprintf_s(yyOutId, "Less ");

	*/
    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::LESS;
}
{MORE} {
	/*
	fprintf_s(yyOutId, "More ");

	*/
    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::MORE;
}


{NEGATION} {
	/*
	fprintf_s(yyOutId, "Negation ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::NEGATION;
}
{ASSIGN} {
	/*
	fprintf_s(yyOutId, "Assign ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::ASSIGN;
}



{PLUS_ASSIGN} {
	/*
	fprintf_s(yyOutId, "+= ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::PLUS_ASSIGN;
}
{MINUS_ASSIGN} {
	/*
	fprintf_s(yyOutId, "-= ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::MINUS_ASSIGN;
}
{MULTIPLY_ASSIGN} {
	/*
	fprintf_s(yyOutId, "*= ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::MULTIPLY_ASSIGN;
}
{DIVIDE_ASSIGN} {
	/*
	fprintf_s(yyOutId, "/= ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::DIVIDE_ASSIGN;
}
{PERCENT_ASSIGN} {
	/*
	fprintf_s(yyOutId, "%= ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::PERCENT_ASSIGN;
}



{AMPERSAND} {
	/*
	fprintf_s(yyOutId, "AMPERSAND ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::AMPERSAND;
}


{LOGIC_AND} {
	/*
	fprintf_s(yyOutId, "&& ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::LOGIC_AND;
}
{LOGIC_OR} {
	/*
	fprintf_s(yyOutId, "|| ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::LOGIC_OR;
}
{LESS_EQUAL} {
	/*
	fprintf_s(yyOutId, "<= ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::LESS_EQUAL;
}
{MORE_EQUAL} {
	/*
	fprintf_s(yyOutId, ">= ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::MORE_EQUAL;
}


{EQUAL} {
	/*
	fprintf_s(yyOutId, "== ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::EQUAL;
}
{NOT_EQUAL} {
	/*
	fprintf_s(yyOutId, "!= ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::NOT_EQUAL;
}


";" {
	/*
	fprintf_s(yyOutId, "Command separator \n");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::COMMAND_SEPARATOR;
}
"," {
	/*
	fprintf_s(yyOutId, "Variable separator ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::VARIABLE_SEPARATOR;
}



{START_IDENTIFICATION} {
	/*
	fprintf_s(yyOutId, "[ ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::START_IDENTIFICATION;
}
{END_IDENTIFICATION} {
	/*
	fprintf_s(yyOutId, "] ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::END_IDENTIFICATION;
}

{CHAR} {
	/*
	fprintf_s(yyOutId, "Char ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::CHAR;
}
{STRING} {
	/*
	fprintf_s(yyOutId, "String ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);
    return token::STRING;
}



{NAME_INTEGER} {
	/*
	fprintf_s(yyOutId, "int ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::NAME_INTEGER;
}
{NAME_FLOAT} {
	/*
	fprintf_s(yyOutId, "float ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::NAME_FLOAT;
}
{NAME_CHAR} {
	/*
	fprintf_s(yyOutId, "char ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::NAME_CHAR;
}
{NAME_STRING} {
	/*
	fprintf_s(yyOutId, "string ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::NAME_STRING;
}
{NAME_LOGIC} {
	/*
	fprintf_s(yyOutId, "bool ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::NAME_LOGIC;
}



{LOGIC} {
	/*
	fprintf_s(yyOutId, "Bool ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::LOGIC;
}
{NAME_RETURN} {
	/*
	fprintf_s(yyOutId, " return ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::NAME_RETURN;
}


{PREFIX_SIGNED} {
	/*
	fprintf_s(yyOutId, "signed ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::PREFIX_SIGNED;
}
{PREFIX_UNSIGNED} {
	/*
	fprintf_s(yyOutId, "unsigned ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::PREFIX_UNSIGNED;
}
{PREFIX_LONG} {
	/*
	fprintf_s(yyOutId, "long ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::PREFIX_LONG;
}




{PREFIX_CONST} {
	/*
	fprintf_s(yyOutId, "const ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::PREFIX_CONST;
}



{IF_OPERATOR} {
	/*
	fprintf_s(yyOutId, "if ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::IF_OPERATOR;
}
{ELSE_OPERATOR} {
	/*
	fprintf_s(yyOutId, "else ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::ELSE_OPERATOR;
}
{SWITCH_OPERATOR} {
	/*
	fprintf_s(yyOutId, "switch ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::SWITCH_OPERATOR;
}
{CASE_OPERATOR} {
	/*
	fprintf_s(yyOutId, "case ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::CASE_OPERATOR;
}
{CASE_ENUMERATOR} {
	/*
	fprintf_s(yyOutId, "case_enumerator ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::CASE_ENUMERATOR;
}



{WHILE_OPERATOR} {
	/*
	fprintf_s(yyOutId, "while ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::WHILE_OPERATOR;
}
{DO_OPERATOR} {
	/*
	fprintf_s(yyOutId, "do ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::DO_OPERATOR;
}
{FOR_OPERATOR} {
	/*
	fprintf_s(yyOutId, "for ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::FOR_OPERATOR;
}
{BREAK_OPERATOR} {
	/*
	fprintf_s(yyOutId, "break ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::BREAK_OPERATOR;
}
{CONTINUE_OPERATOR} {
	/*
	fprintf_s(yyOutId, "continue ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::CONTINUE_OPERATOR;
}


{Identificator} {
	/*
	fprintf_s(yyOutId, "Identificator ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::Identificator;
}


{START_LIST_ARGUMENTS} {
	/*
	fprintf_s(yyOutId, "START_LIST_ARGUMENTS ");

	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::START_LIST_ARGUMENTS;
}
{END_LIST_ARGUMENTS} {
	/*
	fprintf_s(yyOutId, "END_LIST_ARGUMENTS ");
	*/

    yylval->stringVal = new std::string(yytext, yyleng);// TODO : fix correct value
    return token::END_LIST_ARGUMENTS;
}


 /* gobble up white-spaces */
[ \t\r]+ {
    yylloc->step();
}

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
