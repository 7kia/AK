#pragma once

#include <vector>
#include <exception>
#include <string>

#include "HybridWalker.h"


class CUnexpectedSymbolsError : public std::runtime_error
{
public:
	CUnexpectedSymbolsError(const std::vector<CLRRowElement>& expectedSym
		, const std::string & unexpectedSym
		, size_t index);
};

class CNoTransitionError : public std::runtime_error
{
public:
	CNoTransitionError(const std::vector<CLRRowElement>& noTransitionRuleSequence);
};

class CLLUnexpectedSymbolsError : public std::runtime_error
{
public:
	CLLUnexpectedSymbolsError(const std::vector<std::string>& expectedSym
		, const std::string & unexpectedSym
		, size_t index);
};

class CLLNoTransitionError : public std::runtime_error
{
public:
	CLLNoTransitionError(const std::vector<std::string>& noTransitionRuleSequence);
};