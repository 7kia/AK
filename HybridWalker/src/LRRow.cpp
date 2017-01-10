#include "stdafx.h"
#include "LRRow.h"

RowElement::RowElement(const std::string & sym
					, size_t transitionIndex
					, bool shift)
	: inputSymbol(sym)
	, transitionIndex(transitionIndex)
	, isShift(shift)
{
}

RowElement::RowElement(const std::string & sym
					, size_t transition
					, Rule rule
					, bool shift)
	: inputSymbol(sym)
	, transitionIndex(transition)
	, rollup(rule)
	, isShift(shift)
{
}
