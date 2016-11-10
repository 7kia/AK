
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
}

/*
//
//
///////////////////////////////////////////
//
//
//
*/

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
//			Двухсимвольные
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
//		Типы и их имена
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
	%left, %right, %nonassoc и %precedence управляют разрешением
	приоритета операторов и правил ассоциативности
*/

/* Block type nodes
%type <calcnode>	constant Variable

*/

/* Планируется добавить поддержку unicode , чтобы русские символы отображались */
%token <stringVal> 		STRING		"string"
%token <stringVal>		CHAR		"char"
%token <boolValue> 		LOGIC		"bool"
%token <integerValue>	INT			"int"
%token <doubleValue>	FLOAT		"float"
%token <stringVal>		Identificator "Id"


%type <calcnode>	Variable
%type <calcnode>	atomexpr powexpr unaryexpr mulexpr addexpr Arithmetic_expression

%type <calcnode>	Left_part_assign Right_part_assign Value
%type <calcnode>	Call_function
%type <calcnode>	Literal Number

/* Block destructors
%destructor { delete $$; } STRING
*/
%destructor { delete $$; } STRING CHAR
%destructor { delete $$; } LOGIC
%destructor { delete $$; } Variable
%destructor { delete $$; } atomexpr powexpr unaryexpr mulexpr addexpr Arithmetic_expression

%destructor { delete $$; } Left_part_assign Right_part_assign Value
%destructor { delete $$; } Call_function 
%destructor { delete $$; } Literal Number

%%

program: 
        Function_block	{ exit(0); }
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
		START_BLOCK
		commands
		END_BLOCK
		;


commands:
		command commands | /* nothing */
		;

command:
		commandContent 
		COMMAND_SEPARATOR  /*  TODO : see Rule.txt */
		;

commandContent:
			Expression | Assign_for_variable |  Any_branching | Any_loop | Any_interrupt_operator | Return_function | 
			;

Variable: 
		Identificator /*  TODO : see ADDRESED_OPERATION*/
		{
			if (!driver.calc.existsVariable(*$1)) 
			{
				error(yyloc, std::string("Unknown variable \"") + *$1 + "\"");
				delete $1;
				YYERROR;
			}
			else 
			{
				$$ = new CValue( driver.calc.getVariable(*$1) );
				delete $1;
			}
		}
		;

		/*
////////////////////////////////////////////////////////////////////
//						Числа
////////////////////////////////////////////////////////////////////
*/
Number : FLOAT 
			{
				$$ = new CValue($1);
			}
		| INT
			{
				$$ = new CValue($1);
			}
		; /* TODO : неоднозначность */
		/*
////////////////////////////////////////////////////////////////////
//
//
//						Типы
//
//
////////////////////////////////////////////////////////////////////
*/

NAME_TYPE	:
		NAME_CHAR | NAME_STRING | NAME_LOGIC
		;

NAME_NUMERIC_TYPES :
		NAME_INTEGER | NAME_FLOAT /* TODO : see need there char */
		;

Literal :
		Number 
			{
				$$ = $1;
			}
		| LOGIC 
			{
				$$ = new CValue($1);
			}
		| CHAR 
			{
				char value = (*$1)[0];// TODO : rewrite, add char to union /\ //
				$$ = new CValue(value);
			}
		| STRING
			{
				$$ = new CValue(*$1);
			}
		;

Prefix_type	: Can_have_const Name_without_const ;
Can_have_const :  /* nothing */ | PREFIX_CONST ;
Name_without_const :  NAME_TYPE | PREFIX_NUMERIC_TYPES Can_be_long NAME_NUMERIC_TYPES;
PREFIX_NUMERIC_TYPES	:  PREFIX_SIGNED | PREFIX_UNSIGNED ;
Can_be_long : /* nothing */ | PREFIX_LONG;

DEFINITION_POINTER	: /* nothing */ | Can_have_const STAR ;


/*
////////////////////////////////////////////////////////////////////
//						Выражения
////////////////////////////////////////////////////////////////////
*/
Expression : Arithmetic_expression 
					{
						driver.calc.expressions.push_back($1);
					}
				| Bool_expression ; /* | bool_expression*/

Arithmetic_signs : PLUS | MINUS | STAR | DIVIDE | PERCENT ;
//Arithmetic_expression : Value Right_arithmetic_expression_part ;

Right_arithmetic_expression_part : /* nothing */ | Arithmetic_signs Arithmetic_expression ;

Bool_signs : LESS | MORE | LOGIC_AND | LOGIC_OR | LESS_EQUAL | MORE_EQUAL | EQUAL | NOT_EQUAL;
Bool_expression : NEGATION Value | Value Right_bool_expression_part;
/*
				| bool_expression '<' Value | bool_expression LESSOREQUALS Value
				| bool_expression '>' Value | bool_expression MOREOREQUALS Value
				| bool_expression EQUALS Value | bool_expression NOTEQUALS Value
				| bool_expression AND Value | bool_expression OR Value
				| '!' bool_expression

*/

Right_bool_expression_part : /* nothing */ | Bool_signs Bool_expression ;


/*//////////////////////////////////////////*/
/*					New code				*/

/*
В каждом действии псевдопеременная $$ обозначает семантическое значение группы,
 которую собирает это правило. Присвоение $$ значения -- основная работа 
 большинства действий. На семантические значения компонентов правила можно 
 ссылаться как на $1, $2 и т.д.
*/
atomexpr : Number
			{
				$$ = $1;
			}
         | Variable
			{
				$$ = $1;
			}
         | START_LIST_ARGUMENTS Arithmetic_expression END_LIST_ARGUMENTS
			{
				$$ = $2;
			}

powexpr	: atomexpr
          {
	      $$ = $1;
	  }
        | atomexpr POWER powexpr
          {
	      $$ = new CNPower(dynamic_cast<CalcNode*>($1), dynamic_cast<CalcNode*>($3));
	  }

unaryexpr : powexpr
            {
		$$ = $1;
	    }
          | PLUS powexpr
            {
		$$ = $2;
	    }
          | MINUS powexpr
            {
		$$ = new CNNegate(dynamic_cast<CalcNode*>($2));
	    }

mulexpr : unaryexpr
			{
				$$ = $1;
			}
			| mulexpr STAR unaryexpr
			{
				$$ = new CNMultiply(dynamic_cast<CalcNode*>($1), dynamic_cast<CalcNode*>($3));
			}
			| mulexpr DIVIDE unaryexpr
			{
				$$ = new CNDivide(dynamic_cast<CalcNode*>($1), dynamic_cast<CalcNode*>($3));
			}
			| mulexpr PERCENT unaryexpr
			{
				$$ = new CNModulo(dynamic_cast<CalcNode*>($1), dynamic_cast<CalcNode*>($3));
			}

addexpr : mulexpr
			{
				$$ = $1;
			}
			| addexpr PLUS mulexpr
			{
				$$ = new CNAdd(dynamic_cast<CalcNode*>($1), dynamic_cast<CalcNode*>($3));
			}
			| addexpr MINUS mulexpr
			{
				$$ = new CNSubtract(dynamic_cast<CalcNode*>($1), dynamic_cast<CalcNode*>($3));
			}

Arithmetic_expression	: addexpr
			{
				$$ = $1;
			}

/*
////////////////////////////////////////////////////////////////////
//
// Комментарии
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

Value:
		Call_function | Variable  | Literal /* TODO : type Value =  CNFunction || CValue */
	;

Assign_for_variable:
					Left_part_assign Assigns Right_part_assign 
					{
							driver.calc.variables[*$1] = static_cast<CalcNode*>($3)->evaluate();// TODO : delete cast
							driver.m_outFile << "Setting variable " << *$1
								<< " = " << driver.calc.variables[*$1] << "\n";
							delete $1;
							delete $3;
					}
					/* TODO : add  */
					;

Assigns : PLUS_ASSIGN | MINUS_ASSIGN | MULTIPLY_ASSIGN | DIVIDE_ASSIGN | PERCENT_ASSIGN | ASSIGN ;

/*----------------------------*/
Init_list_values		: 
				START_BLOCK { driver.m_idsFile << "\nStart Init_list_values ";  }
				Value_in_list Another_values_in_list 				
				END_BLOCK { driver.m_idsFile << "\nEnd Init_list_values ";  }
				;

Value_in_list	:	Value | Init_list_values ;
Another_values_in_list	:
						VARIABLE_SEPARATOR Value_in_list Another_values_in_list | /* nothing */
						;

Left_part_assign: Init_variable | Variable ;
Right_part_assign: Value | Init_list_values ;
/*----------------------------*/

Init_variable:
				 Type_initialization Name_init_variable
				 ; /* instead " " <common separator> */

Name_init_variable:  Variable | Array_element;
Array_element : Variable First_identification Other_identification;
First_identification : START_IDENTIFICATION Value END_IDENTIFICATION ;
Other_identification : First_identification Other_identification | /* nothing */ ;

/*                     		\/ Types.txt		*/

Type_initialization :
					Prefix_type    
					DEFINITION_POINTER  
					;
/*
////////////////////////////////////////////////////////////////////
//
//
// Функции
//
//
////////////////////////////////////////////////////////////////////
*/
Function_imp_or_init : Function_implementation | Function_init;

Function_init : 
				Type_initialization Function_name List_arguments/* TODO : add separator */
				;
Function_main : 
				Type_initialization NAME_MAIN_FUNCTION List_arguments commandBlock 
				{	
				 	driver.m_idsFile << "\n End main() \n";
					
				}
				/* TODO : add separator */
				;

/* Three low string equal (<function implementation> | <function init>)+*/
Function_block : 
				Definition_function Other_function_imp_or_init;
				; 
Definition_function : Function_imp_or_init COMMAND_SEPARATOR;
Other_function_imp_or_init : Definition_function Other_function_imp_or_init | /* nothing */;

Function_name : Identificator ;
/*
////////////////////////////////////////////////////////////////////
//
// Условия
//
////////////////////////////////////////////////////////////////////
*/
Any_branching : Usual_branching | Switch_branching;

/* TODO : переделать "(" <expression<bool>> ")" */ 
Usual_branching : IF_OPERATOR Condition_part commandBlock Can_have_else_part ;

Condition_part: List_values ;
Can_have_else_part : /* nothing */ | Else_part;
Else_part : ELSE_OPERATOR Else_content ;
Else_content : Usual_branching | commandBlock Can_have_else_part;

Switch_branching : SWITCH_OPERATOR Check_value Switch_block ;
Check_value : START_LIST_ARGUMENTS Value END_LIST_ARGUMENTS; 

Switch_block : START_BLOCK Body_switch END_BLOCK;
Body_switch : /* nothing */ | Sequence_cases commandBlock Body_switch; /* (<all>)* */
Sequence_cases : Case_sequence Other_sequence_cases ;/* (<all>)+ */
Other_sequence_cases : Case_sequence Other_sequence_cases | /* nothing */ ; 
Case_sequence : CASE_OPERATOR Value CASE_ENUMERATOR;

// /\ должна ли быть именно *в Switch_block, то есть может ли switch быть пустым

/*
////////////////////////////////////////////////////////////////////
//
// Циклы
//
////////////////////////////////////////////////////////////////////
*/
Any_loop : Loop_with_precondition | Loop_with_postcondition | Loop_with_counter;
// TODO : переделать "(" <expression<bool>> ")"
Loop_with_precondition :  WHILE_OPERATOR Condition_part commandBlock;
Condition_part :  START_LIST_ARGUMENTS Value END_LIST_ARGUMENTS; /* TODO : see correctness, was <expression<bool>> instead Value */

Loop_with_postcondition :  DO_OPERATOR commandBlock WHILE_OPERATOR Condition_part ;

Loop_with_counter :   FOR_OPERATOR  START_LIST_ARGUMENTS  Parameters_for END_LIST_ARGUMENTS   commandBlock;

Parameters_for :  Start_value_for COMMAND_SEPARATOR Condition_end_for COMMAND_SEPARATOR Next_value_counter;
Start_value_for :  Assign_for_variable ;/* TODO : see can replace on Assign_for_variable */
Condition_end_for :  Bool_expression ; /* TODO : see correctness */
Next_value_counter :  Assign_for_variable | Arithmetic_expression; /* TODO : see correctness */


Any_interrupt_operator :  CONTINUE_OPERATOR  | BREAK_OPERATOR ; 
/*
<reserve loop literal> :  WHILE_OPERATOR | DO_OPERATOR | FOR_OPERATOR | CONTINUE_OPERATOR |  BREAK_OPERATOR ;
*/

/*
///////////////////////////
// Список значении для вызовов функции
///////////////////////////
*/
List_values : 
				START_LIST_ARGUMENTS Set_values END_LIST_ARGUMENTS 
				;
/* Two low string equal Value  (VARIABLE_SEPARATOR Value )?*/
Set_values : Value Other_values | /* nothing */;
Other_values : VARIABLE_SEPARATOR Value Other_values | /* nothing */;
/*
///////////////////////////
// Список значении для вызовов функции
///////////////////////////
*/
List_arguments : 
				START_LIST_ARGUMENTS Set_arguments END_LIST_ARGUMENTS
				;
/* Two low string equal Value  (VARIABLE_SEPARATOR Value )?*/
Set_arguments : Init_variable Other_arguments | /* nothing */;
Other_arguments : VARIABLE_SEPARATOR Init_variable Other_arguments | /* nothing */;

Call_function : Function_name List_values; 

Function_implementation : Function_main | Function_init commandBlock ;

Return_function : NAME_RETURN Value;

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
