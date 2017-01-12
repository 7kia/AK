#pragma once

#include <vector>
#include <exception>
#include <string>

#include "HybridWalker.h"

class CUnexpectedSymbolsError : public std::runtime_error
{
public:
	CUnexpectedSymbolsError(const std::vector<CLRRowElement>& expectedSym, const std::string & unexpectedSym, size_t index);
};

class CNoTransitionError : public std::runtime_error
{
public:
	CNoTransitionError(const std::vector<CLRRowElement>& noTransitionRuleSequence);
};