#pragma once

#include "Grammar.h"
#include <assert.h>
#include <string>

class SToken
{
public:
	SToken();
	~SToken();
	SToken(const SToken &token);
	SToken& operator=(const SToken &token);// TODO: check correctness
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