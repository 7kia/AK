#include "stdafx.h"

#include "Lexer.h"
#include <iostream>
#include <sstream>

using namespace std;

CLexer::CLexer(const std::string & line)
    : m_sources(line)
    , m_peep(m_sources)
    , m_keywords({
		//////////////////////////////////
		// Типы данных
		{ "void", TokensId::TK_VOID },
		{ "int", TokensId::TK_INTEGER },
		{ "float", TokensId::TK_FLOAT },
		{ "string", TokensId::TK_STRING },
		{ "bool", TokensId::TK_BOOL },

		//////////////////////////////////
		// Префиксы типов
		{ "signed", TokensId::TK_SIGNED },
		{ "unsigned", TokensId::TK_UNSIGNED },
		{ "const", TokensId::TK_CONST },
		{ "long", TokensId::TK_LONG },
		//////////////////////////////////
		// Системные функции
		{ "printf", TokensId::TK_PRINT },
		//{ "sizeof", TokensId::TK_SIZEOF },
		//////////////////////////////////
        { "return", TokensId::TK_RETURN },

		//////////////////////////////////
		// Операторы условии
		{ "if", TokensId::TK_IF },
		{ "else", TokensId::TK_ELSE },
		{ "switch", TokensId::TK_SWITH },
		{ "case", TokensId::TK_CASE },
		//////////////////////////////////
		// Операторы циклов
		{ "while", TokensId::TK_WHILE },
		{ "do", TokensId::TK_DO },
		{ "for", TokensId::TK_FOR },

		{ "break", TokensId::TK_BREAK },
		{ "continue", TokensId::TK_CONTINUE },
		

      })
{
}

#define RECOGNIZE_TWO_SYMBOL_TOKEN(TOKEN_NAME, TOKEN_ID)	\
{															\
	if (twoNextSymbols == TOKEN_NAME)					\
	{\
		data.value = twoNextSymbols.to_string();\
		m_peep.remove_prefix(2);\
		return TOKEN_ID;\
	}\
}

#define RECOGNIZE_ONE_SYMBOL_TOKEN(TOKEN_NAME, TOKEN_ID)	\
{															\
	if(m_peep[0] == TOKEN_NAME)\
	{\
		data.value = m_peep[0];\
		m_peep.remove_prefix(1);\
		return TOKEN_ID;\
	}\
}

TokensId CLexer::Scan(SToken &data)
{

  	/////////////////////////////////////////////////////
	// Comments

	///////////////////
	// Extension(TODO : is correct translate ?) multi comment
	///*
	if ( (data.id == TokensId::TK_EXTENSION_MULTI_STRING_COMMENT)
	||
	(data.id == TokensId::TK_START_MULTI_STRING_COMMENT) )
	{
		boost::string_ref twoNextSymbols;
		data.value.clear();

		while (!m_peep.empty())
		{
			twoNextSymbols = m_peep.substr(0, 2);
			if (twoNextSymbols == END_MULTI_STRING_COMMENT)
			{		
				if (!data.value.empty())
				{
					data.id = TokensId::TK_EXTENSION_MULTI_STRING_COMMENT;
					return TokensId::TK_NONE;
				}

				data.value = END_MULTI_STRING_COMMENT;
				data.id = TokensId::TK_END_MULTI_STRING_COMMENT;
				m_peep.remove_prefix(2);
				return TokensId::TK_NONE;
			}

			data.value += m_peep[0];
			data.id = TokensId::TK_EXTENSION_MULTI_STRING_COMMENT;
			m_peep.remove_prefix(1);
		}

		data.id = TokensId::TK_EXTENSION_MULTI_STRING_COMMENT;
		return TokensId::TK_NONE;
	}

	//*/
	///////////////////
	
	SkipSpaces();// TODO : see need whitespace

	/////////////////////////////////////////////////////
	// Three-symbols operations
	boost::string_ref threeNextSymbols = m_peep.substr(0, 3);

	if (threeNextSymbols == NAME_LEFT_SHIFT_ASSIGN)
	{
		data.value = threeNextSymbols.to_string();
		m_peep.remove_prefix(3);
		return TokensId::TK_LEFT_SHIFT_ASSIGN;
	}
	else if (threeNextSymbols == NAME_RIGHT_SHIFT_ASSIGN)
	{
		data.value = threeNextSymbols.to_string();
		m_peep.remove_prefix(3);
		return TokensId::TK_RIGHT_SHIFT_ASSIGN;
	}
	/////////////////////////////////////////////////////
	// Comments
	boost::string_ref twoNextSymbols = m_peep.substr(0, 2);

	if (twoNextSymbols == ONE_STRING_COMMENT)
	{
		data.value = m_peep.to_string();
		data.id = TokensId::TK_ONE_STRING_COMMENT;
		m_peep.clear();

		return TokensId::TK_NONE;
	}
	else if (twoNextSymbols == START_MULTI_STRING_COMMENT)
	{	
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		data.id = TokensId::TK_START_MULTI_STRING_COMMENT;
		return TokensId::TK_NONE;
	}
	else if (twoNextSymbols == END_MULTI_STRING_COMMENT)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_END_MULTI_STRING_COMMENT;
	}
	/////////////////////////////////////////////////////
	// Two-symbols operations
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_NOT_EQUAL, TokensId::TK_NOT_EQUALS)
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_EQUAL, TokensId::TK_EQUALS)
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_LESS_OR_EQUAL, TokensId::TK_LESS_OR_EQUAL)
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_MORE_OR_EQUAL, TokensId::TK_MORE_OR_EQUAL)
	// Assign operators
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_PLUS_ASSIGN, TokensId::TK_PLUS_ASSIGN)
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_MINUS_ASSIGN, TokensId::TK_MINUS_ASSIGN)
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_DIVIDE_ASSIGN, TokensId::TK_DIVIDE_ASSIGN)
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_MULTIPLY_ASSIGN, TokensId::TK_MULTIPLY_ASSIGN)
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_PERCENT_ASSIGN, TokensId::TK_PERCENT_ASSIGN)
	// Logic operators
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_AND, TokensId::TK_LOGIC_AND)
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_OR, TokensId::TK_LOGIC_OR)
	// Increment and decrement
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_INCREMENT, TokensId::TK_INCREMENT)
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_DECREMENT, TokensId::TK_DECREMENT)
	// Bit shift to left and right
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_LEFT_SHIFT, TokensId::TK_LEFT_SHIFT)
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_RIGHT_SHIFT, TokensId::TK_RIGHT_SHIFT)
	// Bit assign operations
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_AND_ASSIGN, TokensId::TK_AND_ASSIGN)
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_XOR_ASSIGN, TokensId::TK_XOR_ASSIGN)
	RECOGNIZE_TWO_SYMBOL_TOKEN(NAME_OR_ASSIGN, TokensId::TK_OR_ASSIGN)
	/////////////////////////////////////////////////////
	if (m_peep.empty())
	{
		return TokensId::TK_NONE;
	}

	/////////////////////////////////////////////////////
	// Parse identifier
	std::string id = ParseIdentifier();
	if (!id.empty())
	{
		return AcceptIdOrKeyword(data, id);
	}
	/////////////////////////////////////////////////////

	/////////////////////////////////////////////////////
	// Parse number
	string intValue = ParseInt();
	

	//if (!intValue.empty())
    //{
	//auto priviousChar = m_sources[m_peep[0]];
	//                           \/ privious token
	if ((m_peep[0] == '.') && (data.id != TokensId::TK_ID))// TODO : see might not only TK_ID
	{
		string doublePart = ParseDoublePart();

		data.value = intValue;
		if (!doublePart.empty())
		{
			data.value += doublePart;

			string exponentialPart = ParseExponentialPart();

			if (!exponentialPart.empty())
			{
				data.value += exponentialPart;
			}
		}

		return TokensId::TK_FLOAT;
	}
	else if (!intValue.empty() && (data.id != TokensId::TK_ID))
	{

		data.value = intValue;
		return TokensId::TK_INTEGER;
	}
	//}


	/////////////////////////////////////////////////////
	// Parse string and char
	if (ParseString(data))
    {
		return TokensId::TK_STRING;
	}
    if (ParseCharLiteral(data))
    {
        return TokensId::TK_CHAR;
    }
	/////////////////////////////////////////////////////

	/////////////////////////////////////////////////////
	// Parse other symbols   
	RECOGNIZE_ONE_SYMBOL_TOKEN(CASE_ENUMERATOR, TokensId::TK_CASE_ENUMERATOR)
	RECOGNIZE_ONE_SYMBOL_TOKEN(CASE_ENUMERATOR, TokensId::TK_NEWLINE)
	//////////////////////////////////////
	// Логические опреаторы
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_NOT_OPERATOR, TokensId::TK_NOT_OPERATOR)
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_BITE_OR, TokensId::TK_BIT_OR)
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_BITE_XOR, TokensId::TK_BIT_XOR)
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_BITE_NOT, TokensId::TK_BIT_NOT)
	//////////////////////////////////////
	// Знаки сравнения
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_LESS, TokensId::TK_LESS)
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_MORE, TokensId::TK_MORE)
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_MORE, TokensId::TK_MORE)
	//////////////////////////////////////
	// Арифметические операции
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_PLUS, TokensId::TK_PLUS)
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_MINUS, TokensId::TK_MINUS)
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_MULTIPLICATION, TokensId::TK_STAR)
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_DIVISION, TokensId::TK_SLASH)
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_DIVISION_BY_REMAIN, TokensId::TK_PERCENT)
	//////////////////////////////////////
	// Разыменование
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_GET_ADDRESS, TokensId::TK_AMPERSAND)
	//////////////////////////////////////
	// Разделители
	RECOGNIZE_ONE_SYMBOL_TOKEN(COMMAND_SEPARATOR, TokensId::TK_SEMICOLON)
	RECOGNIZE_ONE_SYMBOL_TOKEN(VARIABLE_SEPARATOR, TokensId::TK_COMMA)
	//////////////////////////////////////
	// Списки команд, аргументов
	RECOGNIZE_ONE_SYMBOL_TOKEN(START_LIST_ARGUMENTS, TokensId::TK_LEFT_PAREN)
	RECOGNIZE_ONE_SYMBOL_TOKEN(END_LIST_ARGUMENTS, TokensId::TK_RIGHT_PAREN)
	RECOGNIZE_ONE_SYMBOL_TOKEN(START_BLOCK, TokensId::TK_LEFT_BRACE)
	RECOGNIZE_ONE_SYMBOL_TOKEN(END_BLOCK, TokensId::TK_RIGHT_BRACE)
	RECOGNIZE_ONE_SYMBOL_TOKEN(START_OPERATOR_INDEX, TokensId::TK_LEFT_SQUARE_BRACKETS)
	RECOGNIZE_ONE_SYMBOL_TOKEN(END_OPERATOR_INDEX, TokensId::TK_RIGHT_SQUARE_BRACKETS)
	//////////////////////////////////////
	// Оператор присвоения и сравнения
	RECOGNIZE_ONE_SYMBOL_TOKEN(NAME_ASSIGMENT, TokensId::TK_ASSIGN)
	/////////////////////////////////////////////////////

	return TokensId::TK_NONE;
}

bool CLexer::IsEndLine() const
{
	return m_peep.empty();
}

std::string CLexer::ParseInt()
{
	string value;
	bool parsedAny = false;

	////////////////////////////////////
	// Not recognize zeros in start
	/*
	if (m_peep.size() >= 2)
	{
		if ((m_peep[0] == '0')
			&&
			isdigit(m_peep[1])
			)
		{
			return std::string();// Признак ошибки
		}
	}
	*/

	if(!IsZeroInStart())
	{
		return std::string();// Признак ошибки
	}
	////////////////////////////////////

	while (!m_peep.empty() && std::isdigit(m_peep[0]))
	{
		parsedAny = true;
		value += m_peep[0];
		m_peep.remove_prefix(1);
	}

	if (!parsedAny)
	{
		return std::string();// Признак ошибки
	}

	if (m_peep.empty() || !(isalpha(m_peep[0])))
	{
		return value;
	}
	return std::string();
}

string CLexer::ParseDoublePart()
{
	bool isDoublePart = false;
	string value = ".";

	m_peep.remove_prefix(1);
	while (!m_peep.empty() && std::isdigit(m_peep[0]))
	{
		isDoublePart = true;
		value += m_peep[0];
		m_peep.remove_prefix(1);
	}

	return value;
}

string CLexer::ParseExponentialPart()
{
	string value;

	/////////////////////////////////////////////
	// Sign part
	if ((m_peep[0] == NAME_PLUS) || (m_peep[0] == NAME_MINUS))
	{
		value += m_peep[0];
	}
	else
	{
		return std::string();// TODO : error
	}
	/////////////////////////////////////////////
	
	/////////////////////////////////////////////
	// Exponential part
	if ((m_peep[1] == 'e') || (m_peep[1] == 'E'))
	{
		value += m_peep[1];
	}
	else
	{
		return std::string();// TODO : error
	}
	/////////////////////////////////////////////
	
	/////////////////////////////////////////////
	// Digit part
	m_peep.remove_prefix(2);

	if (!IsZeroInStart())
	{
		return std::string();// Признак ошибки
	}

	while (!m_peep.empty() && std::isdigit(m_peep[0]))
	{
		value += m_peep[0];
		m_peep.remove_prefix(1);
	}
	/////////////////////////////////////////////

	return value;
}

bool CLexer::IsZeroInStart()
{
	////////////////////////////////////
	// Not recognize zeros in start
	if (m_peep.size() >= 2)
	{
		if ((m_peep[0] == '0')
			&&
			isdigit(m_peep[1])
			)
		{
			return false;// Признак ошибки
		}
	}

	return true;
}

std::string CLexer::ParseIdentifier()
{
    size_t size = 0;

	// In start identifier must not digit
	if (!IsIdentifierSymbol(m_peep[0]) || isdigit(m_peep[0]))
	{
		return "";
	}

    while (!m_peep.empty() && IsIdentifierSymbol(m_peep[size]))
    {
        ++size;
    }
    std::string value = m_peep.substr(0, size).to_string();
    m_peep.remove_prefix(size);
    return value;
}

void CLexer::SkipSpaces()
{
    size_t count = 0;
    while (count < m_peep.size() && std::isspace(m_peep[count]))
    {
        ++count;
    }
    m_peep.remove_prefix(count);
}

bool CLexer::ParseString(SToken &data)
{
	if (m_peep[0] != '\"')
	{
		return false;
	}

	m_peep.remove_prefix(1);
	size_t quotePos = m_peep.find('\"');
	if (quotePos == boost::string_ref::npos)
	{
		m_peep.clear();

		return true;
	}

	data.value = '\"' + std::string(m_peep.substr(0, quotePos)) + '\"';
	m_peep.remove_prefix(quotePos + 1);
	return true;
}

// TODO : copy privious method, might need rewrite
bool CLexer::ParseCharLiteral(SToken &data)
{
	if (m_peep[0] != '\'')
	{
		return false;
	}

	m_peep.remove_prefix(1);
	size_t quotePos = m_peep.find('\'');
	if (quotePos == boost::string_ref::npos)
	{
		m_peep.clear();

		return true;
	}

	data.value = '\'' + std::string(m_peep.substr(0, quotePos)) + '\'';
	m_peep.remove_prefix(quotePos + 1);
	return true;
}

TokensId CLexer::AcceptIdOrKeyword(SToken &data, const boost::string_ref id)
{
    if (id == NAME_TRUE)
    {
        data.value = NAME_TRUE;
        return TokensId::TK_BOOL;
    }
    else if (id == NAME_FALSE)
    {
        data.value = NAME_FALSE;
        return TokensId::TK_BOOL;
    }

    auto it = m_keywords.find(std::string(id));
    if (it != m_keywords.end())
    {
		data.value = it->first;
        return static_cast<TokensId>(it->second);
    }

    data.value = std::string(id);
    return TokensId::TK_ID;
}

bool CLexer::IsIdentifierSymbol(const char symbol) const
{
	return isalnum(symbol) || (symbol == '_');
}

