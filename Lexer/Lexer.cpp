#include "stdafx.h"

#include "Lexer.h"
#include "Grammar.h"
#include <iostream>
#include <sstream>

using namespace std;

CLexer::CLexer(const std::string & line)
    : m_sources(line)
    , m_peep(m_sources)
    , m_keywords({
		//////////////////////////////////
		// ���� ������
		{ "void", TokensId::TK_VOID },
		{ "int", TokensId::TK_INTEGER },
		{ "float", TokensId::TK_FLOAT },
		{ "string", TokensId::TK_STRING },
		{ "bool", TokensId::TK_BOOL },

		//////////////////////////////////
		// �������� �����
		{ "signed", TokensId::TK_SIGNED },
		{ "unsigned", TokensId::TK_UNSIGNED },
		{ "const", TokensId::TK_CONST },
		{ "long", TokensId::TK_LONG },
		//////////////////////////////////
		// ��������� �������
		{ "printf", TokensId::TK_PRINT },
		{ "sizeof", TokensId::TK_SIZEOF },
		//////////////////////////////////
        { "return", TokensId::TK_RETURN },

		//////////////////////////////////
		// ��������� �������
		{ "if", TokensId::TK_IF },
		{ "else", TokensId::TK_ELSE },

		//////////////////////////////////
		// ��������� ������
		{ "while", TokensId::TK_WHILE },
		{ "do", TokensId::TK_DO },
		{ "for", TokensId::TK_FOR },

		{ "break", TokensId::TK_BREAK },
		{ "continue", TokensId::TK_CONTINUE },
		

      })
{
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
					return TokensId::TK_EXTENSION_MULTI_STRING_COMMENT;
				}

				data.value = END_MULTI_STRING_COMMENT;
				data.id = TokensId::TK_END_MULTI_STRING_COMMENT;
				m_peep.remove_prefix(2);
				return TokensId::TK_END_MULTI_STRING_COMMENT;
			}

			data.value += m_peep[0];
			data.id = TokensId::TK_EXTENSION_MULTI_STRING_COMMENT;
			m_peep.remove_prefix(1);
		}

		return TokensId::TK_EXTENSION_MULTI_STRING_COMMENT;
	}

	//*/
	///////////////////
	
	SkipSpaces();// TODO : see need whitespace

	boost::string_ref twoNextSymbols = m_peep.substr(0, 2);
	/////////////////////////////////////////////////////
	// Comments
	if (twoNextSymbols == ONE_STRING_COMMENT)
	{
		data.value = m_peep.to_string();
		data.id = TokensId::TK_ONE_STRING_COMMENT;
		m_peep.clear();

		return TokensId::TK_ONE_STRING_COMMENT;
	}
	else if (twoNextSymbols == START_MULTI_STRING_COMMENT)
	{	
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		data.id = TokensId::TK_START_MULTI_STRING_COMMENT;
		return TokensId::TK_START_MULTI_STRING_COMMENT;
	}
	else if (twoNextSymbols == END_MULTI_STRING_COMMENT)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_END_MULTI_STRING_COMMENT;
	}
	/////////////////////////////////////////////////////
	// Two-symbols operations
	else if (twoNextSymbols == NAME_NOT_EQUAL)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_NOT_EQUALS;
	}
	else if (twoNextSymbols == NAME_EQUAL)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_EQUALS;
	}
	else if (twoNextSymbols == NAME_LESS_OR_EQUAL)
	{		
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_LESS_OR_EQUAL;	
	}
	else if (twoNextSymbols == NAME_MORE_OR_EQUAL)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_MORE_OR_EQUAL;
	}
	// Assign operators
	else if (twoNextSymbols == NAME_PLUS_ASSIGN)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_PLUS_ASSIGN;
	}
	else if (twoNextSymbols == NAME_MINUS_ASSIGN)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_MINUS_ASSIGN;
	}
	else if (twoNextSymbols == NAME_DIVIDE_ASSIGN)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_DIVIDE_ASSIGN;
	}
	else if (twoNextSymbols == NAME_MULTIPLY_ASSIGN)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_MULTIPLY_ASSIGN;
	}
	// Logic operators
	else if (twoNextSymbols == NAME_AND)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_LOGIC_AND;
	}
	else if (twoNextSymbols == NAME_OR)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_LOGIC_OR;
	}
	// Increment and decrement
	else if (twoNextSymbols == NAME_INCREMENT)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_INCREMENT;
	}
	else if (twoNextSymbols == NAME_DECREMENT)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_DECREMENT;
	}
	// Bit shift to left and right
	else if (twoNextSymbols == NAME_LEFT_SHIFT)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_LEFT_SHIFT;
	}
	else if (twoNextSymbols == NAME_RIGHT_SHIFT)
	{
		data.value = twoNextSymbols.to_string();
		m_peep.remove_prefix(2);
		return TokensId::TK_RIGHT_SHIFT;
	}
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
    switch (m_peep[0])
    {
		//////////////////////////////////////
		// ����� ������
	case NEWLINE_SYMBOL:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_NEWLINE;

		//////////////////////////////////////
		// ���������� ���������
	case NAME_NOT_OPERATOR:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_NOT_OPERATOR;
	case NAME_BITE_OR:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_BIT_OR;
	case NAME_BITE_XOR:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_BIT_XOR;
	case NAME_BITE_NOT:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_BIT_NOT;
		//////////////////////////////////////
		// ����� ���������
    case NAME_LESS:
		data.value = m_peep[0];
        m_peep.remove_prefix(1);
        return TokensId::TK_LESS;
	case NAME_MORE:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_MORE;// TODO : not work
		//////////////////////////////////////
		// �������������� ��������
    case NAME_PLUS:
		data.value = m_peep[0];
        m_peep.remove_prefix(1);
        return TokensId::TK_PLUS;
    case NAME_MINUS:
		data.value = m_peep[0];
        m_peep.remove_prefix(1);
        return TokensId::TK_MINUS;
    case NAME_MULTIPLICATION:
		data.value = m_peep[0];
        m_peep.remove_prefix(1);
        return TokensId::TK_STAR;
    case NAME_DIVISION:
		data.value = m_peep[0];
        m_peep.remove_prefix(1);
        return TokensId::TK_SLASH;
	case NAME_DIVISION_BY_REMAIN:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_PERCENT;
		//////////////////////////////////////
		// �������������
	case NAME_GET_ADDRESS:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_AMPERSAND;
		//////////////////////////////////////
		// �����������
	case COMMAND_SEPARATOR:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_SEMICOLON;
    case VARIABLE_SEPARATOR:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_COMMA;

		//////////////////////////////////////
		// ������ ������, ����������
	case START_LIST_ARGUMENTS:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_LEFT_PAREN;
	case END_LIST_ARGUMENTS:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_RIGHT_PAREN;
	case START_BLOCK:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_LEFT_BRACE;
	case END_BLOCK:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_RIGHT_BRACE;
	case START_OPERATOR_INDEX:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_LEFT_SQUARE_BRACKETS;
	case END_OPERATOR_INDEX:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_RIGHT_SQUARE_BRACKETS;
		//////////////////////////////////////
		// �������� ���������� � ���������
	case NAME_ASSIGMENT:
		data.value = m_peep[0];
		m_peep.remove_prefix(1);
		return TokensId::TK_ASSIGN;
	}
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
			return std::string();// ������� ������
		}
	}
	*/

	if(!IsZeroInStart())
	{
		return std::string();// ������� ������
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
		return std::string();// ������� ������
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
		return std::string();// ������� ������
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
			return false;// ������� ������
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

