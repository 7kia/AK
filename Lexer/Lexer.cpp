#include "stdafx.h"

#include "Lexer.h"
#include "Grammar.h"
#include <iostream>
#include <sstream>

using namespace std;

CLexer::CLexer(const std::string & line
				, std::ostream &output
				, std::ostream &errors)
    : m_sources(line)
    , m_peep(m_sources)
    , m_keywords({
        { "return", TokensId::TK_RETURN },
      })
{
}

TokensId CLexer::Scan(SToken &data)
{
    SkipSpaces();// TODO : see need whitespace

    if (m_peep.empty())
    {
		return TokensId::TK_NONE;
    }

	/////////////////////////////////////////////////////
	// Parse identifier
	std::string id = ParseIdentifier();
	if (!id.empty())
	{
		return AcceptIdOrKeyword(data);
	}
	/////////////////////////////////////////////////////

	/////////////////////////////////////////////////////
	// Parse number
	string intValue = ParseInt();
	
	if (!std::isnan(intValue))
    {
		if (m_peep[0] == '.')
		{
			double doublePart = ParseDoublePart();

			if (!std::isnan(doublePart))
			{
				data.doubleValue = intValue + doublePart;
				return TK_DOUBLE;
			}
		}
		
		data.intValue = static_cast<int>(intValue);
		return TK_INT;		
    }


	/////////////////////////////////////////////////////
	// Parse string
    if (ParseString(data))
    {
        return TokensId::TK_STRING;
    }
	/////////////////////////////////////////////////////

	/////////////////////////////////////////////////////
	// Parse other symbols
    switch (m_peep[0])
    {
    case NAME_LESS:
        m_peep.remove_prefix(1);
        return TokensId::TK_LESS;
	case NAME_MORE:
		m_peep.remove_prefix(1);
		return TokensId::TK_MORE;// TODO : not work
    case NAME_PLUS:
        m_peep.remove_prefix(1);
        return TokensId::TK_PLUS;
    case NAME_MINUS:
        m_peep.remove_prefix(1);
        return TokensId::TK_MINUS;
    case NAME_MULTIPLICATION:
        m_peep.remove_prefix(1);
        return TokensId::TK_STAR;
    case NAME_DIVISION:
        m_peep.remove_prefix(1);
        return TokensId::TK_SLASH;
    case VARIABLE_SEPARATOR:// TODO : write test for it
        m_peep.remove_prefix(1);
        return TokensId::TK_COMMA;
    case NAME_DIVISION_BY_REMAIN:
        m_peep.remove_prefix(1);
        return TokensId::TK_PERCENT;
    case START_LIST_ARGUMENTS:
        m_peep.remove_prefix(1);
        return TokensId::TK_LPAREN;
    case END_LIST_ARGUMENTS:
        m_peep.remove_prefix(1);
        return TokensId::TK_RPAREN;
    case NAME_ASSIGMENT:
        if (m_peep.length() >= 2 && (m_peep[1] == NAME_ASSIGMENT))
        {
            m_peep.remove_prefix(2);
            return TokensId::TK_EQUALS;
        }
        m_peep.remove_prefix(1);
        return TokensId::TK_ASSIGN;
    }
	/////////////////////////////////////////////////////

    return TokensId::TK_NONE;
}

std::string CLexer::ParseInt()
{
	string value;
	bool parsedAny = false;
	while (!m_peep.empty() && std::isdigit(m_peep[0]))
	{
		parsedAny = true;
		value += m_peep[0]
		m_peep.remove_prefix(1);
	}

	if (!parsedAny)
	{
		return std::string();// Признак ошибки
	}

	if ((m_peep.empty() || !(isalpha(m_peep[0]))
	{
		return value;
	}
	return std::string();
}

// returns NaN if cannot parse double.
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

	if (!isDoublePart)
	{
		return std::string();
	}

	return value;
}

// returns NaN if cannot parse double.
double CLexer::ParseDouble()
{
    double value = 0;
    bool parsedAny = false;
    while (!m_peep.empty() && std::isdigit(m_peep[0]))
    {
        parsedAny = true;
        const int digit = m_peep[0] - '0';
        value = value * 10.0f + double(digit);
        m_peep.remove_prefix(1);
    }

    if (!parsedAny)
    {
        return std::numeric_limits<double>::quiet_NaN();
    }

	/////////////////////////////////////////////////
	// After number would space symbol(s), 
	if (isalpha(m_peep[0]))
	{
		throw std::logic_error("Next symbol after number is incorrect ");
	}
	/////////////////////////////////////////////////
	// If not double part then return integer value
    if (m_peep.empty() || (m_peep[0] != '.'))
    {
        return value;
    }
	/////////////////////////////////////////////////
    m_peep.remove_prefix(1);
    double factor = 1.f;
    while (!m_peep.empty() && std::isdigit(m_peep[0]))
    {
        const int digit = m_peep[0] - '0';
        factor *= 0.1f;
        value += factor * double(digit);
        m_peep.remove_prefix(1);
    }

    return value;
}

std::string CLexer::ParseIdentifier()
{
    size_t size = 0;

	// In start identifier must not digit
	if (!isalpha(m_peep[0]))
	{
		return "";
	}

    while (!m_peep.empty() && std::isalnum(m_peep[size]))
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

	data.value = m_peep.substr(0, quotePos);
	m_peep.remove_prefix(quotePos + 1);
	return true;
}

TokensId CLexer::AcceptIdOrKeyword(SToken &data, boost::string_ref id)
{
    if (id == NAME_TRUE)
    {
        data.value = std::string(id);
        return TokensId::TK_BOOL;
    }
    else if (id == NAME_FALSE)
    {
        data.value = std::string(id);
        return TokensId::TK_BOOL;
    }

    auto it = m_keywords.find(std::string(id));
    if (it != m_keywords.end())
    {
        return static_cast<TokensId>(it->second);
    }

    data.value = std::string(id);
    return TokensId::TK_ID;
}

