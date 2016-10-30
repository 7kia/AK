#include "stdafx.h"

#include "Lexer.h"
#include "Grammar.h"
#include <iostream>
#include <sstream>
#include "Converter.h"

using namespace std;

CConverter::CConverter()
{
}

SToken CConverter::Convert(yytokentype id, const std::string & data)
{
	m_sources = data;
	m_peep = m_sources;

	SToken result;
	SkipSpaces();// TODO : see need whitespace

	
	/////////////////////////////////////////////////////
	// Parse number
	string intValue = ParseInt();
	

	//if (!intValue.empty())
    //{
	//auto priviousChar = m_sources[m_peep[0]];
	//                           \/ privious token

	if ((m_peep[0] == '.'))// TODO : see might not only TK_ID
	{
		string doublePart = ParseDoublePart();

		result.stringValue = intValue;
		if (!doublePart.empty())
		{
			result.stringValue += doublePart;

			string exponentialPart = ParseExponentialPart();

			if (!exponentialPart.empty())
			{
				result.stringValue += exponentialPart;
			}
		}

		result.id = yytokentype::FLOAT;
		return result;
	}
	else if (!intValue.empty())
	{

		result.stringValue = intValue;
		result.id = yytokentype::INT;
		return result;
	}
	//}
	result.id = yytokentype::BYE;
	assert(false);
	return result;
}

bool CConverter::IsEndLine() const
{
	return m_peep.empty();
}

std::string CConverter::ParseInt()
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

string CConverter::ParseDoublePart()
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

string CConverter::ParseExponentialPart()
{
	string value;

	/////////////////////////////////////////////
	// Sign part
	if ((m_peep[0] == '+') || (m_peep[0] == '-'))
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

bool CConverter::IsZeroInStart()
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

std::string CConverter::ParseIdentifier()
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

void CConverter::SkipSpaces()
{
    size_t count = 0;
    while (count < m_peep.size() && std::isspace(m_peep[count]))
    {
        ++count;
    }
    m_peep.remove_prefix(count);
}

bool CConverter::ParseString()
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

	//data.value = '\"' + std::string(m_peep.substr(0, quotePos)) + '\"';
	m_peep.remove_prefix(quotePos + 1);
	return true;
}

// TODO : copy privious method, might need rewrite
bool CConverter::ParseCharLiteral()
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

	//data.value = '\'' + std::string(m_peep.substr(0, quotePos)) + '\'';
	m_peep.remove_prefix(quotePos + 1);
	return true;
}

bool CConverter::IsIdentifierSymbol(const char symbol) const
{
	return isalnum(symbol) || (symbol == '_');
}

