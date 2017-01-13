#pragma once
#include "Transition.h"
#include <vector>
#include <stack>


class LL1Walker
{
public:
	LL1Walker(const LLTable & table);

	bool CheckInputSequence(const std::vector<std::string>& inputStr);

private:
	CTransition GetCurrentTransition(const CLL1RowElement & row);

	std::stack<CTransition> m_transitions;

	LLTable m_LLTable;
};
