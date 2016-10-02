#pragma once

#include "Grammar.h"

struct SToken
{
	SToken();
	SToken(const std::string & value, TokensId id);

	std::string		value;
	TokensId		id = TokensId::TK_NONE;
};
