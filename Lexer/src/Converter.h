#pragma once

#include <cctype>
#include <string>
#include <map>
#include <functional>
#include <boost/utility/string_ref.hpp>
#include "../Lexer.h"
#include "../Token.h"

class CConverter
{
public:
    CConverter();// TODO : see need it

	SToken		Convert(TokenType id, const std::string &data);
	bool		IsEndLine() const;
private:
	std::string							ParseInt();
	std::string							ParseDoublePart();
	std::string							ParseExponentialPart();
    std::string							ParseIdentifier();
    void								SkipSpaces();
    bool								ParseString();// TODO : not work
	bool								ParseCharLiteral();// TODO : not work

	bool								IsZeroInStart();
	bool								IsIdentifierSymbol(const char symbol) const;
private:
    std::string							m_sources;
    boost::string_ref					m_peep;
};
