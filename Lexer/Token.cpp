#include "Token.h"

SToken::SToken()
{
}

SToken::SToken(const std::string & value, TokensId id)
	: value(value)
	, id(id)
{
}
