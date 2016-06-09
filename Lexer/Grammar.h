#pragma once

#include <string>

//////////////////////////////////////////////////////////////////////
// Tokens id
enum class TokensId
{

	  TK_NONE = 0
	, TK_INTEGER = 1
	, TK_DOUBLE
	, TK_STRING
	, TK_BOOL
	, TK_LESS
	, TK_MORE
	, TK_EQUALS
	, TK_LESS_OR_EQUAL
	, TK_MORE_OR_EQUAL
	, TK_PLUS
	, TK_MINUS
	, TK_STAR
	, TK_SLASH
	, TK_PERCENT
	, TK_NEWLINE
	, TK_ID
	, TK_LPAREN
	, TK_RPAREN
	, TK_END
	, TK_COMMA
	, TK_ASSIGN
	, TK_PRINT
	, TK_RETURN
	, TK_IF
	, TK_ELSE
	, TK_WHILE
	, TK_DO
	,
};

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//
//								Alphabet
//
//////////////////////////////////////////////////////////////////////
static const char VARIABLE_SEPARATOR = ',';

static const char WHITE_SPACE = ' ';// TODO : rename
static const char TAB_SYMBOL = '\t';
//static const std::string COMMON_SEPARATORS[] = { WHITE_SPACE , TAB_SYMBOL };

static const char START_BLOCK = '{';
static const char END_BLOCK = '}';
static const char START_LIST_ARGUMENTS = '(';
static const char END_LIST_ARGUMENTS = ')';
static const char CASE_ENUMERATOR = ':';
//////////////////////////////////////////////////////////////////////
// Reserve words
static const std::string NAME_IF = "if";// TODO : not enough words
static const std::string NAME_TRUE = "true";
static const std::string NAME_FALSE = "false";
//////////////////////////////////////////////////////////////////////
// Operators

// Arithmetic
static const char NAME_DIVISION_BY_REMAIN = '%';
static const char NAME_MULTIPLICATION = '*';
static const char NAME_PLUS = '+';
static const char NAME_MINUS = '-';
static const char NAME_DIVISION = '/';
static const char NAME_LESS = '<';
static const std::string NAME_LESS_OR_EQUAL = "<=";
static const char NAME_MORE = '>';
static const std::string NAME_MORE_OR_EQUAL = ">=";
//static const std::string NAME_DEGREE = "^";// TODO : degree or XOR

// Common
static const std::string NAME_COMPARE = "==";
static const std::string NAME_NOT_EQUAL = "!=";
static const char NAME_ASSIGMENT = '=';

// Logic
static const std::string NAME_AND = "&&";
static const std::string NAME_OR = "||";

// Bit
static const char NAME_BITE_AND = '&';
static const char NAME_BITE_OR = '|';
//////////////////////////////////////////////////////////////////////