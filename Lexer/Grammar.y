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
// TODO : transfer to Grammar.h
#include "src/AST/ASTNodes.h"
#include "src/ScannerPrivate.h"

// TODO : transfer after Grammar.h
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
	unsigned int		stringId;

	IFunctionAST*			pFunction;
	IStatementAST*		pStatetment;
	IExpressionAST*		pExpression;

	ExpressionList*		pExpressionList;
	StatementsList*		pStatementList;
	//NamesList					nameList;// TODO : see need it
	NamesList*			pNameList;
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
%token <stringVal> 		STRING		"string"
%token <doubleValue>	FLOAT		"float"
%token <integerValue>	INT			"int"
%token <stringVal>		CHAR		"char"
%token <boolValue> 		BOOL		"bool"
%token <stringId> ID "Id"

%type <pExpression> expression constant variable function_call
%type <pFunction> function_declaration
%type <pStatetment> statement statement_line
%type <pStatementList> statement_list block
%type <pNameList> parameter_list 
%type <pExpressionList> expression_list
/* Block destructors
%destructor { delete $$; } STRING
*/
%destructor { delete $$; } STRING CHAR

%destructor { delete $$; } expression constant variable function_call
%destructor { delete $$; } function_declaration
%destructor { delete $$; } statement statement_line
%destructor { delete $$; } statement_list block
%destructor { delete $$; } parameter_list
%destructor { delete $$; } expression_list

%%

epsilon : /*empty*/

constant : BOOL 
			{
				EmplaceAST<CLiteralAST>($$, CValue::FromBoolean($1));
			}
		| INT 
		{
			EmplaceAST<CLiteralAST>($$, CValue::FromInt($1));
		}
		| FLOAT 
		{
			EmplaceAST<CLiteralAST>($$, CValue::FromDouble($1));
		}
		| STRING
		{
			EmplaceAST<CLiteralAST>($$, CValue::FromString(*$1));
		}

variable : ID
			{
				EmplaceAST<CVariableRefAST>($$, $1);
			}

function_call : ID START_LIST_ARGUMENTS END_LIST_ARGUMENTS
				{
					EmplaceAST<CCallAST>($$, $1, ExpressionList());
				}
				| ID START_LIST_ARGUMENTS expression_list END_LIST_ARGUMENTS
				{
					auto pList = Take($3);
					EmplaceAST<CCallAST>($$, $1, std::move(*pList));
				}

expression : constant 
		| variable 
		| START_LIST_ARGUMENTS expression END_LIST_ARGUMENTS
		{
			MovePointer($2, $$);
		}
        | PLUS expression 
		{
			EmplaceAST<CUnaryExpressionAST>($$, UnaryOperation::Plus, Take($2));
		}
		| MINUS expression 
		{
			EmplaceAST<CUnaryExpressionAST>($$, UnaryOperation::Minus, Take($2));
		}
		| NOT expression
		{
			EmplaceAST<CUnaryExpressionAST>($$, UnaryOperation::Plus, Take($2));
		}
        | expression LESS expression 
		{
			EmplaceAST<CBinaryExpressionAST>($$, Take($1), BinaryOperation::Less, Take($3));
		}
		| expression EQUALS expression
		{
			EmplaceAST<CBinaryExpressionAST>($$, Take($1), BinaryOperation::Equals, Take($3));
		}

        | expression AND expression
		{
			EmplaceAST<CBinaryExpressionAST>($$, Take($1), BinaryOperation::LogicAnd, Take($3));
		} 
		| expression OR expression
		{
			EmplaceAST<CBinaryExpressionAST>($$, Take($1), BinaryOperation::LogicOr, Take($3));
		}
        | expression PLUS expression 
		{
			EmplaceAST<CBinaryExpressionAST>($$, Take($1), BinaryOperation::Add, Take($3));
		}
		| expression MINUS expression
		{
			EmplaceAST<CBinaryExpressionAST>($$, Take($1), BinaryOperation::Substract, Take($3));
		}
        | expression STAR expression 
		{
			EmplaceAST<CBinaryExpressionAST>($$, Take($1), BinaryOperation::Multiply, Take($3));
		}
		| expression DIVIDE expression
		{
			EmplaceAST<CBinaryExpressionAST>($$, Take($1), BinaryOperation::Divide, Take($3));
		}
        | expression PERCENT expression
		{
			EmplaceAST<CBinaryExpressionAST>($$, Take($1), BinaryOperation::Modulo, Take($3));
		}

        | function_call

expression_list : epsilon 
				{
				$$ = nullptr;
				}
				| expression 
				{
					CreateList($$, $1);
				}
				| expression_list VARIABLE_SEPARATOR expression
				{
					ConcatList($$, $1, $3);
				}

statement : PRINT expression
			{
			// TODO : see need instead expression expression_list
				EmplaceAST<CPrintAST>($$, Take($2));
			}
          | ID ASSIGN expression
			{
				EmplaceAST<CAssignAST>($$, $1, Take($3));// TODO : warning can not work
			}
          | NAME_RETURN expression
			{
				EmplaceAST<CReturnAST>($$, Take($2));
			}
          | IF_OPERATOR expression block
			{
				auto pThenBody = Take($3);
				EmplaceAST<CIfAst>($$, Take($2), std::move(*pThenBody));
			}
          | IF_OPERATOR expression block ELSE_OPERATOR block
			{
				auto pThenBody = Take($3);
				auto pElseBody = Take($5);
				EmplaceAST<CIfAst>($$, Take($2), std::move(*pThenBody), std::move(*pElseBody));
			}
          | WHILE_OPERATOR expression block
			{
				auto pBody = Take($3);
				EmplaceAST<CWhileAst>($$, Take($2), std::move(*pBody));
			}
          | DO_OPERATOR NEWLINE statement_list WHILE_OPERATOR expression BLOCK_END
			{
				auto pBody = Take($3);
				EmplaceAST<CRepeatAst>($$, Take($5), std::move(*pBody));
			}
          | DO_OPERATOR NEWLINE WHILE_OPERATOR expression BLOCK_END
			{
				EmplaceAST<CRepeatAst>($$, Take($4));
			}
		  /* | epsilon */

statement_line : error NEWLINE 
				{
				// TODO : see need NEWLINE
				$$ = nullptr;
				}
				| statement NEWLINE
				{
					MovePointer($1, $$);
				}

statement_list : statement_line 
					{
						CreateList($$, $1);
					}
				| statement_list statement_line
					{
						ConcatList($$, $1, $2);
					}

block : NEWLINE statement_list BLOCK_END
{
	$$ = $2;
}

block : NEWLINE BLOCK_END
{
	$$ = nullptr;
}

parameter_list : ID 
					{
						auto list = Make<NamesList>();
						list->emplace_back( $1 );
						$$ = list.release();
					}
				| parameter_list VARIABLE_SEPARATOR ID
				{
					auto pList = Take($1);
					pList->emplace_back($3);
					$$ = pList.release();
				}

function_declaration : FUNCTION ID START_LIST_ARGUMENTS parameter_list END_LIST_ARGUMENTS block
						{
							auto pParameters = Take($4);
							auto pBody = Take($6);
							EmplaceAST<CFunctionAST>($$, $2, std::move(*pParameters), std::move(*pBody));
						}

                     | FUNCTION ID START_LIST_ARGUMENTS END_LIST_ARGUMENTS block
						
{
							auto pBody = Take($5);
							EmplaceAST<CFunctionAST>($$, $2, std::vector<unsigned>(), std::move(*pBody));
						}
toplevel_statement : function_declaration 
					{
						 driver.m_ast.AddFunction(Take($1));
					}
					| statement
					{
						driver.m_ast.AddStatement(Take($1));
					}

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
