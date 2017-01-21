#include "stdafx.h"
#include "Rule.h"

Rule::Rule(const SToken & output, size_t size)
	: tokenRule(output)
	, size(size)
{
}
