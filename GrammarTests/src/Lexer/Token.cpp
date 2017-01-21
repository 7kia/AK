#include "stdafx.h"
#include "Token.h"

SToken::SToken()
{
}

SToken::SToken(const std::string & value, TokensId id)
	: value(value)
	, id(id)
{
}

bool const operator==(SToken const & first, SToken const & second)
{
	return first.id == second.id;
}
