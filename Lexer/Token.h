#pragma once

#include "Grammar.h"
#include <assert.h>

class SToken
{
public:
	SToken();
	~SToken();
	SToken(const SToken &token);
//////////////////////////////////////////////////////////////////////
// Data
public:
    // position in source code.
    size_t position = 0;

	yytokentype id;
	union
	{
		// token value (always 0 for most tokens).
		double doubleValue;

		std::string keyword;
		std::string stringValue;
		char		charValue;
	};
};