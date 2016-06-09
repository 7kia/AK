#pragma once

#include <cctype>
#include <string>
#include <map>
#include <functional>
#include <boost/utility/string_ref.hpp>
#include "Grammar.h"
#include "Token.h"

class CLexer
{
public:
    CLexer(const std::string & line);

	TokensId Scan(SToken &data);

private:
	std::string							ParseInt();
	std::string							ParseDoublePart();
    std::string							ParseIdentifier();
    void								SkipSpaces();
    bool								ParseString(SToken &data);
	TokensId							AcceptIdOrKeyword(SToken &data, const boost::string_ref id);

private:
    const std::string					m_sources;
    boost::string_ref					m_peep;

	const std::map<std::string, TokensId>	m_keywords;
};
