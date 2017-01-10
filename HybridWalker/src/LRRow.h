#pragma once

#include <vector>
#include <string>

#include "Rule.h"

struct RowElement
{
	RowElement(const std::string & sym
		, size_t transition
		, bool shift);
	RowElement(const std::string & sym
		, size_t transition
		, Rule rule
		, bool shift);

	std::string				inputSymbol = "";
	size_t					transitionIndex;
	boost::optional<Rule>	rollup;
	bool					isShift;
};

typedef std::vector<Rule> Rules;
typedef std::vector<std::vector<RowElement>> LRTable;