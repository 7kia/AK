#pragma once
#include "Transition.h"
#include "LRRow.h"
#include <vector>
#include <stack>

using Tokens = std::vector<std::string>;

class HybridWalker
{
public:
	HybridWalker(const Tokens & tokens, const LRTable & table);
	//////////////////////////////////////////////////////////////////////
	// Methods
public:
	bool						CheckInputSequence();

	//////////////////////////////////////////////////////////////////////
	// Data
private:
	Tokens						m_inputTokens;
	LRTable						m_LRtable;
	std::stack<std::string>		m_elements;
	std::stack<CTransition>		m_transitions;
};

