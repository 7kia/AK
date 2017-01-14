#pragma once
#include <string>
#include <boost/optional.hpp>
#include "Lexer\Token.h"

struct Rule
{
	Rule(const SToken & output, size_t size);
	SToken		tokenRule;
	size_t			size;
};
