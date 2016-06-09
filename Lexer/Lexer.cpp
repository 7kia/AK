#include "stdafx.h"

#include "Lexer.h"
#include "Grammar.h"
#include <iostream>
#include <sstream>

CLexer::CLexer(unsigned lineNo
				, std::string const& line
				, CStringPool & pool
				, ErrorHandler const &handler)
    : m_lineNo(lineNo)
    , m_sources(line)
    , m_peep(m_sources)
    , m_stringPool(pool)
    , m_onError(handler)
    , m_keywords({
        { "do",     TokensId::TK_DO },
        { "if",     TokensId::TK_IF },
        { "end",    TokensId::TK_END },
        { "else",	TokensId::TK_ELSE },
        { "while",  TokensId::TK_WHILE },
        { "print",  TokensId::TK_PRINT },
        { "return", TokensId::TK_RETURN },
        { "def",    TokensId::TK_FUNCTION },
      })
{
}

int CLexer::Scan(SToken &data)
{
    SkipSpaces();// TODO : see need whitespace
    data.line = m_lineNo;
    data.column = 1 + unsigned(m_peep.data() - m_sources.c_str());

    if (m_peep.empty())
    {
        return 0;
    }

	/////////////////////////////////////////////////////
	// Parse identifier
	std::string id = ParseIdentifier();
	if (!id.empty())
	{
		return AcceptIdOrKeyword(data, std::move(id));
	}
	/////////////////////////////////////////////////////

	/////////////////////////////////////////////////////
	// Parse number // TODO : not pars double, because program will not stable
    double value = ParseDouble();
    if (!std::isnan(value))
    {
        data.value = value;
        return TokensId::TK_NUMBER;
    }
	/////////////////////////////////////////////////////
	/*
	////////////////////////////////////
	// Parse number
	double intValue = ParseInt();
	
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


	double CLexer::ParseInt()
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

		if (m_peep.empty() || (m_peep[0] != '.'))// TODO : might add suffix u, L(for example 1.f, 4u)
		{
			return value;
		}
	}

	// returns NaN if cannot parse double.
	double CLexer::ParseDoublePart()
	{
		bool isDoublePart = false;
		double value = 0;

		m_peep.remove_prefix(1);
		double factor = 1.f;
		while (!m_peep.empty() && std::isdigit(m_peep[0]))
		{
			isDoublePart = true;
			const int digit = m_peep[0] - '0';
			factor *= 0.1f;
			value += factor * double(digit);
			m_peep.remove_prefix(1);
		}

		if (!isDoublePart)
		{
			return std::numeric_limits<double>::quiet_NaN();
		}

		return value;
	}
	*/


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
	//case NAME_MORE:
		//m_peep.remove_prefix(1);
		//return TokensId::TK_MORE;// TODO : not work
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

	/////////////////////////////////////////////////////
    // on error, return EOF
    OnError("unknown lexem", data);
    return 0;
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
		OnError("Next symbol after number is incorrect ", SToken());
		return std::numeric_limits<double>::quiet_NaN();
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
        OnError("missed end quote", data);
        data.stringId = m_stringPool.Insert(m_peep.to_string());
        m_peep.clear();

        return true;
    }

    boost::string_ref value = m_peep.substr(0, quotePos);
    data.stringId = m_stringPool.Insert(value.to_string());
    m_peep.remove_prefix(quotePos + 1);

    return true;
}

int CLexer::AcceptIdOrKeyword(SToken &data, std::string && id)
{
    if (id == NAME_TRUE)
    {
        data.boolValue = true;
        return TokensId::TK_BOOL;
    }
    else if (id == NAME_FALSE)
    {
        data.boolValue = false;
        return TokensId::TK_BOOL;
    }

    auto it = m_keywords.find(id);
    if (it != m_keywords.end())
    {
        return it->second;
    }

    data.stringId = m_stringPool.Insert(id);
    return TokensId::TK_ID;
}

void CLexer::OnError(const char message[], SToken &data)
{
    if (m_onError)
    {
        std::stringstream formatter;
        formatter << message << " at (" << data.line << "," << data.column << ")";
        m_onError(formatter.str());
    }
}
