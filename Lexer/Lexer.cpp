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
		// Типы данных
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

		//////////////////////////////////
        { "return", TokensId::TK_RETURN },

		//////////////////////////////////
		// Операторы условии
		{ "if", TokensId::TK_IF },
		{ "else", TokensId::TK_ELSE },

		//////////////////////////////////
		// Операторы циклов
		{ "while", TokensId::TK_WHILE },
		{ "do", TokensId::TK_DO },
		{ "for", TokensId::TK_FOR },

		

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
		return AcceptIdOrKeyword(data, id);
	}
	/////////////////////////////////////////////////////

	/////////////////////////////////////////////////////
	// Parse number
	string intValue = ParseInt();
	
	1.;
	.0;
	if (!intValue.empty())
    {
		if (m_peep[0] == '.')
		{
			string doublePart = ParseDoublePart();

			if (!doublePart.empty())
			{
				data.value = intValue + doublePart;
				return TokensId::TK_FLOAT;
			}
		}
		else
		{

			data.value = intValue;
			return TokensId::TK_INTEGER;

		}
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
		//////////////////////////////////////
		// Знаки сравнения
    case NAME_LESS:
		data.value = NAME_LESS;
        m_peep.remove_prefix(1);
        return TokensId::TK_LESS;
	case NAME_MORE:
		data.value = NAME_MORE;
		m_peep.remove_prefix(1);
		return TokensId::TK_MORE;// TODO : not work

		//////////////////////////////////////
		// Арифметические операции
    case NAME_PLUS:
		data.value = NAME_PLUS;
        m_peep.remove_prefix(1);
        return TokensId::TK_PLUS;
    case NAME_MINUS:
		data.value = NAME_MINUS;
        m_peep.remove_prefix(1);
        return TokensId::TK_MINUS;
    case NAME_MULTIPLICATION:
		data.value = NAME_MULTIPLICATION;
        m_peep.remove_prefix(1);
        return TokensId::TK_STAR;
    case NAME_DIVISION:
		data.value = NAME_DIVISION;
        m_peep.remove_prefix(1);
        return TokensId::TK_SLASH;
	case NAME_DIVISION_BY_REMAIN:
		data.value = NAME_DIVISION_BY_REMAIN;
		m_peep.remove_prefix(1);
		return TokensId::TK_PERCENT;
		//////////////////////////////////////
		// Разделители
	case COMMAND_SEPARATOR:
		data.value = COMMAND_SEPARATOR;
		m_peep.remove_prefix(1);
		return TokensId::TK_SEMICOLON;
    case VARIABLE_SEPARATOR:
		data.value = VARIABLE_SEPARATOR;
        m_peep.remove_prefix(1);
        return TokensId::TK_COMMA;

		//////////////////////////////////////
		// Списки команд, аргументов
    case START_LIST_ARGUMENTS:
		data.value = START_LIST_ARGUMENTS;
        m_peep.remove_prefix(1);
        return TokensId::TK_LEFT_PAREN;
    case END_LIST_ARGUMENTS:
		data.value = END_LIST_ARGUMENTS;
        m_peep.remove_prefix(1);
        return TokensId::TK_RIGHT_PAREN;
	case START_BLOCK:
		data.value = START_BLOCK;
		m_peep.remove_prefix(1);
		return TokensId::TK_LEFT_BRACE;
	case END_BLOCK:
		data.value = END_BLOCK;
		m_peep.remove_prefix(1);
		return TokensId::TK_RIGHT_BRACE;

		//////////////////////////////////////
		// Оператор присвоения и сравнения
    case NAME_ASSIGMENT:
        if (m_peep.length() >= 2 && (m_peep[1] == NAME_ASSIGMENT))
        {
			data.value = NAME_ASSIGMENT;
			data.value += NAME_ASSIGMENT;
            m_peep.remove_prefix(2);
            return TokensId::TK_EQUALS;
        }
		data.value = NAME_ASSIGMENT;
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

	// Not recognize zeros in start
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

	if (m_peep.empty() || !(isalpha(m_peep[0])) )
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

std::string CLexer::ParseIdentifier()
{
    size_t size = 0;

	// In start identifier must not digit
	if (!IsIdentifierSymbol(m_peep[0]) || isdigit(m_peep[0]))
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

	data.value = std::string(m_peep.substr(0, quotePos));
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

