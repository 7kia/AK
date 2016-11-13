%{

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO : YYSTYPE - it is token
//#define YYSTYPE double

extern int yylex();

#include "src/driver.h"
#include "src/scanner.h"
#include "src/AST/ASTNodes.h"
#include "src/ScannerPrivate.h"

using namespace scanner_private;
/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start program

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="example"

/* set the parser's class identifier */
%define "parser_class_name" "Parser"

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose


 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/
/*	
//
// There value token 
//
*/
%union {

    int  				integerValue;
    double 				doubleValue;
	bool				boolValue;
    std::string*		stringVal;// TODO : see need separately char
	class CNode*		calcnode;

	ExpressionListPtr	pExpList;
	StatementListPtr	pStatList;
	StatementPtr		pStat;
	ExpressionPtr		pExp;
	FunctionPtr			pFunc;
	NamesList			nameList;
	NamesListPtr		pNameList;
}

/*
//
//
///////////////////////////////////////////
//
//
//
*/
%token NEWLINE  "end of line"
%token NUMBER   "Number constant"
%token STRING   "String constant"
%token BOOL     "Bool constant"
%token BLOCK_END "end"
%token FUNCTION "def"
%token PRINT    "print"
/*TODO : delete /\\\ */

%token END  0  "end of file"
%token NAME_MAIN_FUNCTION

%token START_BLOCK
%token END_BLOCK

%token DIGIT_MORE_ZERO			/* TODO : see need these + */
%token DIGIT_ZERO				
%token DIGIT					

%token PLUS
%token MINUS
%token DIVIDE 
%token STAR
%token PERCENT
%token POWER
%token LESS
%token MORE

%token NEGATION
%token ASSIGN

%token AMPERSAND
/*
//			ƒвухсимвольные
*/
%token PLUS_ASSIGN
%token MINUS_ASSIGN
%token MULTIPLY_ASSIGN
%token DIVIDE_ASSIGN
%token PERCENT_ASSIGN


%token LOGIC_AND
%token LOGIC_OR
%token LESS_EQUAL
%token MORE_EQUAL

%token EQUAL
%token NOT_EQUAL

/* Need for grammar */
%token Have_sign

%token REFERENCE

%token COMMAND_SEPARATOR
%token VARIABLE_SEPARATOR

%token ONLY_STRING_COMMENT
%token MULTI_STRING_COMMENT

%token START_IDENTIFICATION
%token END_IDENTIFICATION

%token ID "ID"
/*
//////////////////////////////
//		“ипы и их имена
//////////////////////////////
*/
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

%token NAME_RETURN

%token START_LIST_ARGUMENTS
%token END_LIST_ARGUMENTS

/* 
	%left, %right, %nonassoc и %precedence управл€ют разрешением
	приоритета операторов и правил ассоциативности
*/
%left LESS EQUALS
%left AND OR NOT
%left PLUS MINUS
%left STAR DIVIDE PERCENT

/* Block type nodes
%type <calcnode>	constant Variable

*/


/* Block destructors
%destructor { delete $$; } STRING
*/


%%

epsilon : /*empty*/

constant : BOOL | NUMBER | STRING

variable : ID

function_call : ID '(' expression_list ')'

expression : constant | variable | '(' expression ')'
        | PLUS expression | MINUS expression | NOT expression
        | expression LESS expression | expression EQUALS expression
        | expression AND expression | expression OR expression
        | expression PLUS expression | expression MINUS expression
        | expression STAR expression | expression DIVIDE expression
        | expression PERCENT expression
        | function_call

expression_list : epsilon | expression | expression_list ',' expression

statement : PRINT expression_list
          | variable '=' expression
          | NAME_RETURN expression
          | IF_OPERATOR expression block
          | IF_OPERATOR expression NEWLINE statement_list ELSE_OPERATOR block
          | IF_OPERATOR expression NEWLINE ELSE_OPERATOR block
          | WHILE_OPERATOR expression block
          | DO_OPERATOR NEWLINE statement_list WHILE_OPERATOR expression BLOCK_END
          | DO_OPERATOR NEWLINE WHILE_OPERATOR expression BLOCK_END

statement_line : error NEWLINE | statement NEWLINE

statement_list : statement_line | statement_list statement_line

block : NEWLINE statement_list BLOCK_END

block : NEWLINE BLOCK_END

parameter_list : ID | parameter_list ID

function_declaration : FUNCTION ID '(' parameter_list ')' block
                     | FUNCTION ID '(' ')' block

toplevel_statement : function_declaration | statement

toplevel_line : NEWLINE | toplevel_statement NEWLINE | error NEWLINE

toplevel_list : toplevel_line | toplevel_list toplevel_line

program : toplevel_list


/*** 
================================================================================================================================
END EXAMPLE - Change the example grammar rules above 
================================================================================================================================
***/

%% /*** Additional Code ***/

void example::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
