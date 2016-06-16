#pragma once

#include <string>
#include <array>
#include <map>
//////////////////////////////////////////////////////////////////////
// Tokens id
enum class TokensId
{

	  TK_NONE = 0

	, TK_INTEGER = 1
	, TK_FLOAT
	, TK_STRING

	, TK_SIGNED
	, TK_UNSIGNED
	, TK_CONST
	, TK_LONG

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

	, TK_ID

	, TK_LEFT_PAREN
	, TK_RIGHT_PAREN
	, TK_LEFT_BRACE
	, TK_RIGHT_BRACE

	, TK_SEMICOLON
	, TK_COMMA

	, TK_ASSIGN

	, TK_PRINT

	, TK_NEWLINE

	, TK_RETURN

	, TK_IF
	, TK_ELSE

	, TK_WHILE
	, TK_DO
	, TK_FOR
	, Amount = TK_FOR + 1// TODO : replace
};

static const std::map<TokensId, std::string> TokensStringPresentation
= {

	{ TokensId::TK_NONE, "Unknow"}

	,{ TokensId::TK_INTEGER, "Integer"}
	,{ TokensId::TK_FLOAT,  "Double"}
	,{ TokensId::TK_STRING, "String"}

	,{ TokensId::TK_SIGNED, "Signed" }
	,{ TokensId::TK_UNSIGNED, "Unsigned" }
	,{ TokensId::TK_CONST, "Const" }
	,{ TokensId::TK_LONG, "Long" }

	,{ TokensId::TK_BOOL, "Bool"}
	,{ TokensId::TK_LESS, "Less"}
	,{ TokensId::TK_MORE, "More"}
	,{ TokensId::TK_EQUALS, "Equal"}
	,{ TokensId::TK_LESS_OR_EQUAL, "Less or equal"}
	,{ TokensId::TK_MORE_OR_EQUAL, "More or equal"}


	,{ TokensId::TK_PLUS, "Plus"}
	,{ TokensId::TK_MINUS, "Minus"}
	,{ TokensId::TK_STAR,  "Star"}
	,{ TokensId::TK_SLASH, "Slash"}
	,{ TokensId::TK_PERCENT, "Percent"}

	,{ TokensId::TK_ID, "Identifier"}

	,{ TokensId::TK_LEFT_PAREN, "Left paren"}
	,{ TokensId::TK_RIGHT_PAREN, "Right paren"}
	,{ TokensId::TK_LEFT_BRACE, "Left brace" }
	,{ TokensId::TK_RIGHT_BRACE, "Right brace" }


	,{ TokensId::TK_SEMICOLON, "Semicolon" }
	,{ TokensId::TK_COMMA, "Comma"}

	,{ TokensId::TK_ASSIGN, "Assign"}

	,{ TokensId::TK_PRINT, "Print"}

	,{ TokensId::TK_NEWLINE, "Newline"}

	,{ TokensId::TK_RETURN, "Return"}

	,{ TokensId::TK_IF, "If"}
	,{ TokensId::TK_ELSE, "Else"}

	,{ TokensId::TK_WHILE, "While"}
	,{ TokensId::TK_DO, "Do"}
	,{ TokensId::TK_FOR, "For"}
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
static const char NEWLINE_SYMBOL = '\n';
//static const std::string COMMON_SEPARATORS[] = { WHITE_SPACE , TAB_SYMBOL };

static const char COMMAND_SEPARATOR = ';';
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