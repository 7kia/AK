#pragma once

#include <string>
#include <array>
#include <map>
//////////////////////////////////////////////////////////////////////
// Tokens id
enum class TokensId
{

	TK_NONE = 0

	, TK_END_CODE = -1
	, TK_INTEGER = 1
	, TK_FLOAT
	, TK_CHAR
	, TK_STRING

	, TK_INTEGER_TYPE
	, TK_FLOAT_TYPE
	, TK_CHAR_TYPE
	, TK_BOOL_TYPE
	, TK_STRING_TYPE

	, TK_SIGNED
	, TK_UNSIGNED
	, TK_CONST
	, TK_LONG

	, TK_VOID
	, TK_BOOL
	, TK_NOT_OPERATOR
	, TK_LESS
	, TK_MORE
	, TK_EQUALS
	, TK_NOT_EQUALS
	, TK_LOGIC_AND
	, TK_LOGIC_OR

	, TK_BIT_AND
	, TK_BIT_OR
	, TK_BIT_XOR// исключающее или
	, TK_LEFT_SHIFT
	, TK_RIGHT_SHIFT
	, TK_BIT_NOT

	, TK_INCREMENT
	, TK_DECREMENT

	, TK_LESS_OR_EQUAL
	, TK_MORE_OR_EQUAL
	, TK_PLUS_ASSIGN
	, TK_MINUS_ASSIGN
	, TK_MULTIPLY_ASSIGN
	, TK_DIVIDE_ASSIGN
	, TK_PERCENT_ASSIGN

	, TK_AND_ASSIGN
	, TK_OR_ASSIGN
	, TK_XOR_ASSIGN
	, TK_LEFT_SHIFT_ASSIGN
	, TK_RIGHT_SHIFT_ASSIGN

	, TK_PLUS
	, TK_MINUS
	, TK_STAR
	, TK_SLASH
	, TK_PERCENT
	, TK_AMPERSAND// TODO : see is correctness name

	, TK_ID

	, TK_LEFT_PAREN
	, TK_RIGHT_PAREN
	, TK_LEFT_BRACE
	, TK_RIGHT_BRACE
	, TK_LEFT_SQUARE_BRACKETS
	, TK_RIGHT_SQUARE_BRACKETS

	, TK_SEMICOLON
	, TK_COMMA

	, TK_ONE_STRING_COMMENT
	, TK_START_MULTI_STRING_COMMENT
	, TK_EXTENSION_MULTI_STRING_COMMENT// TODO : is correct translate?
	, TK_END_MULTI_STRING_COMMENT

	, TK_ASSIGN

	, TK_PRINT
	, TK_READ
	, TK_SIZEOF

	, TK_NEWLINE
	, TK_NEWLINE_FOR_MULTI_STRING_COMMENT

	, TK_RETURN

	, TK_IF
	, TK_ELSE
	, TK_SWITH
	, TK_CASE
	, TK_CASE_ENUMERATOR

	, TK_WHILE
	, TK_DO
	, TK_FOR

	, TK_BREAK
	, TK_CONTINUE

	// Rule tokens
	, RULE_CONSTANT
	, RULE_EXPRESSION

	, Amount
};

static const std::map<TokensId, std::string> TokensStringPresentation
= {

	{ TokensId::TK_NONE, "Unknow" }

	,{ TokensId::TK_VOID, "Void" }
	,{ TokensId::TK_INTEGER, "Integer" }
	,{ TokensId::TK_FLOAT,  "Double" }
	,{ TokensId::TK_CHAR, "Char" }
	,{ TokensId::TK_STRING, "String" }

	,{ TokensId::TK_INTEGER_TYPE, "Integer type" }
	,{ TokensId::TK_FLOAT_TYPE,  "Double  type" }
	,{ TokensId::TK_CHAR_TYPE, "Char type" }
	,{ TokensId::TK_STRING_TYPE, "String type" }

	,{ TokensId::TK_SIGNED, "Signed" }
	,{ TokensId::TK_UNSIGNED, "Unsigned" }
	,{ TokensId::TK_CONST, "Const" }
	,{ TokensId::TK_LONG, "Long" }

	,{ TokensId::TK_BOOL, "Bool" }
	,{ TokensId::TK_NOT_OPERATOR, "Not operator" }
	,{ TokensId::TK_LESS, "Less" }
	,{ TokensId::TK_MORE, "More" }
	,{ TokensId::TK_EQUALS, "Equal" }
	,{ TokensId::TK_NOT_EQUALS, "Not equal" }
	,{ TokensId::TK_LOGIC_AND, "Logic and" }
	,{ TokensId::TK_LOGIC_OR, "Logic or" }

	,{ TokensId::TK_BIT_AND, "Bit and" }
	,{ TokensId::TK_BIT_OR, "Bit or" }
	,{ TokensId::TK_BIT_XOR, "Bit xor" }
	,{ TokensId::TK_LEFT_SHIFT, "Bit shift to left" }
	,{ TokensId::TK_RIGHT_SHIFT, "Bit shift to right" }
	,{ TokensId::TK_BIT_NOT, "Bit not" }

	,{ TokensId::TK_INCREMENT, "Increment" }
	,{ TokensId::TK_DECREMENT, "Decrement" }


	,{ TokensId::TK_LESS_OR_EQUAL, "Less or equal" }
	,{ TokensId::TK_MORE_OR_EQUAL, "More or equal" }

	,{ TokensId::TK_PLUS_ASSIGN, "Plus assign" }
	,{ TokensId::TK_MINUS_ASSIGN, "Minus assign" }
	,{ TokensId::TK_MULTIPLY_ASSIGN, "Multiply assign" }
	,{ TokensId::TK_DIVIDE_ASSIGN, "Divide assign" }
	,{ TokensId::TK_PERCENT_ASSIGN, "Persent assign" }

	,{ TokensId::TK_AND_ASSIGN, "And assign" }
	,{ TokensId::TK_OR_ASSIGN, "Or assign" }
	,{ TokensId::TK_XOR_ASSIGN, "Xor assign" }
	,{ TokensId::TK_LEFT_SHIFT_ASSIGN, "Left shift assign" }
	,{ TokensId::TK_RIGHT_SHIFT_ASSIGN, "Right shift assign" }


	,{ TokensId::TK_PLUS, "Plus" }
	,{ TokensId::TK_MINUS, "Minus" }
	,{ TokensId::TK_STAR,  "Star" }
	,{ TokensId::TK_SLASH, "Slash" }
	,{ TokensId::TK_PERCENT, "Percent" }
	,{ TokensId::TK_AMPERSAND, "Ampersand" }

	,{ TokensId::TK_ID, "Identifier" }

	,{ TokensId::TK_LEFT_PAREN, "Left paren" }
	,{ TokensId::TK_RIGHT_PAREN, "Right paren" }
	,{ TokensId::TK_LEFT_BRACE, "Left brace" }
	,{ TokensId::TK_RIGHT_BRACE, "Right brace" }
	,{ TokensId::TK_LEFT_SQUARE_BRACKETS, "Left square brackets" }
	,{ TokensId::TK_RIGHT_SQUARE_BRACKETS, "Right square brackets" }


	,{ TokensId::TK_SEMICOLON, "Semicolon" }
	,{ TokensId::TK_COMMA, "Comma" }

	,{ TokensId::TK_ONE_STRING_COMMENT, "One strign comment" }
	,{ TokensId::TK_START_MULTI_STRING_COMMENT, "Start multi-strign comment" }
	,{ TokensId::TK_EXTENSION_MULTI_STRING_COMMENT, "Content multi-string comment" }// TODO : is correct translate?
	,{ TokensId::TK_END_MULTI_STRING_COMMENT, "End multi-strign comment" }

	,{ TokensId::TK_ASSIGN, "Assign" }

	,{ TokensId::TK_PRINT, "Print" }
	,{ TokensId::TK_SIZEOF, "Sizeof" }

	,{ TokensId::TK_NEWLINE, "Newline" }

	,{ TokensId::TK_RETURN, "Return" }

	,{ TokensId::TK_IF, "If" }
	,{ TokensId::TK_ELSE, "Else" }
	,{ TokensId::TK_SWITH, "Swith" }
	,{ TokensId::TK_CASE, "Case" }
	,{ TokensId::TK_CASE_ENUMERATOR, "Case enumerator" }


	,{ TokensId::TK_WHILE, "While" }
	,{ TokensId::TK_DO, "Do" }
	,{ TokensId::TK_FOR, "For" }

	,{ TokensId::TK_BREAK, "Break" }
	,{ TokensId::TK_CONTINUE, "Continue" }

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

//////////////////////////////////////////////////////////////////////
// Comments
static const std::string ONE_STRING_COMMENT = "//";
static const std::string START_MULTI_STRING_COMMENT = "/*";
static const std::string END_MULTI_STRING_COMMENT = "*/";
//////////////////////////////////////////////////////////////////////

static const char START_BLOCK = '{';
static const char END_BLOCK = '}';

static const char START_LIST_ARGUMENTS = '(';
static const char END_LIST_ARGUMENTS = ')';

static const char START_OPERATOR_INDEX = '[';
static const char END_OPERATOR_INDEX = ']';

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
static const std::string NAME_PLUS_ASSIGN = "+=";
static const std::string NAME_MINUS_ASSIGN = "-=";
static const std::string NAME_DIVIDE_ASSIGN = "/=";
static const std::string NAME_MULTIPLY_ASSIGN = "*=";
static const std::string NAME_PERCENT_ASSIGN = "%=";

static const std::string NAME_AND_ASSIGN = "&=";
static const std::string NAME_XOR_ASSIGN = "^=";
static const std::string NAME_OR_ASSIGN = "|=";
static const std::string NAME_LEFT_SHIFT_ASSIGN = "<<=";
static const std::string NAME_RIGHT_SHIFT_ASSIGN = ">>=";

static const std::string NAME_INCREMENT = "++";
static const std::string NAME_DECREMENT = "--";

//static const std::string NAME_DEGREE = "^";// TODO : degree or XOR

// Common
static const std::string NAME_EQUAL = "==";
static const std::string NAME_NOT_EQUAL = "!=";
static const char NAME_ASSIGMENT = '=';

static const char NAME_GET_ADDRESS = '&';

// Logic
static const char NAME_NOT_OPERATOR = '!';
static const std::string NAME_AND = "&&";
static const std::string NAME_OR = "||";

// Bit
static const char NAME_BITE_AND = '&';
static const char NAME_BITE_OR = '|';
static const char NAME_BITE_XOR = '^';
static const std::string NAME_LEFT_SHIFT = "<<";
static const std::string NAME_RIGHT_SHIFT = ">>";
static const char NAME_BITE_NOT = '~';

//////////////////////////////////////////////////////////////////////

struct SToken
{
	SToken();
	SToken(const std::string & value, TokensId id);

	friend bool const operator ==(SToken const& first, SToken const& second);

	std::string		value;
	TokensId		id = TokensId::TK_NONE;
};

// 	Ready tokes
static const SToken endCodeToken("End code", TokensId::TK_END_CODE);
static const SToken otherToken("other", TokensId::TK_NONE);

static const SToken startBlockToken("{", TokensId::TK_LEFT_BRACE);
static const SToken endBlockToken("}", TokensId::TK_RIGHT_BRACE);

static const SToken startListToken("(", TokensId::TK_LEFT_PAREN);
static const SToken endListToken(")", TokensId::TK_RIGHT_PAREN);


static const SToken intToken("int", TokensId::TK_INTEGER);
static const SToken floatToken("float", TokensId::TK_FLOAT);
static const SToken charToken("char", TokensId::TK_CHAR);
static const SToken stringToken("string", TokensId::TK_STRING);

static const SToken idToken("ID", TokensId::TK_ID);
static const SToken startListArgumentToken("START_LIST_ARGUMENTS", TokensId::TK_LEFT_PAREN);
static const SToken endListArgumentToken("END_LIST_ARGUMENTS", TokensId::TK_RIGHT_PAREN);

static const SToken expToken("exp", TokensId::RULE_EXPRESSION);
static const SToken plusToken("+", TokensId::TK_PLUS);
static const SToken minusToken("-", TokensId::TK_MINUS);
static const SToken devideToken("/", TokensId::TK_SLASH);
static const SToken starToken("*", TokensId::TK_STAR);

static const SToken logicAndToken("&&", TokensId::TK_LOGIC_AND);
static const SToken logicOrToken("||", TokensId::TK_LOGIC_OR);

static const SToken intTypeToken("int type", TokensId::TK_INTEGER_TYPE);
static const SToken floatTypeToken("float type", TokensId::TK_FLOAT_TYPE);
static const SToken charTypeToken("char type ", TokensId::TK_CHAR_TYPE);
static const SToken logicTypeToken("bool type ", TokensId::TK_BOOL_TYPE);
static const SToken stringTypeToken("string type", TokensId::TK_STRING_TYPE);

static const SToken printToken("print", TokensId::TK_PRINT);
static const SToken readToken("read", TokensId::TK_READ);

static const SToken returnToken("return", TokensId::TK_RETURN);
static const SToken ifToken("if", TokensId::TK_IF);
static const SToken elseToken("else", TokensId::TK_ELSE);
static const SToken whileToken("while", TokensId::TK_WHILE);


