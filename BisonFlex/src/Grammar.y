%{
#pragma warning( disable : 4065 603 )  

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO : YYSTYPE - it is token
//#define YYSTYPE double

extern int yylex();

#include "src/driver.h"
#include "src/scanner.h"

// TODO : transfer after Grammar.h
/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer.lex

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
%parse-param { class CCompilerDriver& driver }

/* verbose error messages */
%error-verbose


 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/
/*	
//
// There value token 
//
*/
%union {
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

%token BLOCK_END "end"
%token FUNCTION "def"
%token PRINT    "print"
/*TODO : delete /\\\ */

%token END  0  "end of file"

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
%token STRING		"string"
%token FLOAT		"float"
%token INT			"int"
%token CHAR			"char"
%token BOOL			"bool"
%token ID			"Id"


%%

epsilon : /*empty*/

constant : BOOL 
		| INT 
		| FLOAT 
		| STRING

variable : ID

function_call : ID START_LIST_ARGUMENTS END_LIST_ARGUMENTS
				| ID START_LIST_ARGUMENTS expression_list END_LIST_ARGUMENTS

expression : constant 
		| function_call
		| variable 
		| START_LIST_ARGUMENTS expression END_LIST_ARGUMENTS
        | PLUS expression 
		| MINUS expression 
        | expression LESS expression 
		| expression EQUALS expression
        | expression PLUS expression 
		| expression MINUS expression
        | expression STAR expression 
		| expression DIVIDE expression
        | expression PERCENT expression


expression_list : 
				expression 
				| expression_list VARIABLE_SEPARATOR expression


Init_list_values : START_BLOCK expression_list END_BLOCK


/*
////////////////////////////////////////////////////////////////////
//
//						“ипы
//
////////////////////////////////////////////////////////////////////
*/
type_reference : NAME_FLOAT			
				| NAME_INTEGER		
				///*
				| NAME_CHAR
				//*/
				| NAME_STRING

				| NAME_LOGIC

/*
////////////////////////////////////////////////////////////////////
//		/\/\				“ипы				/\/\\\\////
////////////////////////////////////////////////////////////////////
*/
statement : //function_call // TODO : see need it
			//| // TODO : add because can call function (for example, Draw(); )
			 PRINT START_LIST_ARGUMENTS expression END_LIST_ARGUMENTS

          | type_reference ID ASSIGN expression

			| type_reference ID ASSIGN Init_list_values

          | NAME_RETURN expression
	
          | IF_OPERATOR START_LIST_ARGUMENTS expression END_LIST_ARGUMENTS block
		  			
          | IF_OPERATOR START_LIST_ARGUMENTS expression END_LIST_ARGUMENTS block ELSE_OPERATOR block

          | WHILE_OPERATOR START_LIST_ARGUMENTS expression END_LIST_ARGUMENTS block

          | DO_OPERATOR block WHILE_OPERATOR START_LIST_ARGUMENTS expression END_LIST_ARGUMENTS

          | DO_OPERATOR WHILE_OPERATOR START_LIST_ARGUMENTS expression END_LIST_ARGUMENTS

		  /* | epsilon */

statement_line : error COMMAND_SEPARATOR 
				| statement COMMAND_SEPARATOR

statement_list : statement_line 
				| statement_list statement_line

block : START_BLOCK statement_list END_BLOCK

block : START_BLOCK END_BLOCK

parameter_decl : type_reference ID

parameter_list : parameter_decl
				| parameter_list VARIABLE_SEPARATOR parameter_decl



function_declaration : type_reference ID parenthesis_parameter_list block


parenthesis_parameter_list : START_LIST_ARGUMENTS END_LIST_ARGUMENTS
							| START_LIST_ARGUMENTS parameter_list END_LIST_ARGUMENTS


toplevel_statement : function_declaration 


toplevel_line : COMMAND_SEPARATOR 
				| toplevel_statement COMMAND_SEPARATOR 
				| error COMMAND_SEPARATOR

toplevel_list : toplevel_line 
				| toplevel_list toplevel_line

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
