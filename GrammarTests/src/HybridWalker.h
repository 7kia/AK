#pragma once
#include "Transition.h"
#include "LRRow.h"
#include <vector>
#include <stack>

using Tokens = std::vector<SToken>;

class HybridWalker
{
public:
	enum class State
	{
		LLCheck
		, LRCheck
		, End
	};

	HybridWalker(LRTable * LRtable
		, LLTable * LLtable
		, State state);
	//////////////////////////////////////////////////////////////////////
	// Methods
public:
	bool						CheckInputSequence(const Tokens & tokens);

	bool						CheckAsLR();
	bool						CheckAsLL();

	CTransition					GetCurrentTransition(const CLL1RowElement & row);
	void						SetState(State state);
	//////////////////////////////////////////////////////////////////////
	// Data
private:
	Tokens						m_inputTokens;
	LRTable	*					m_LRTable = nullptr;
	LLTable	*					m_LLTable = nullptr;

	std::stack<std::string>		m_elements;
	std::stack<CTransition>		m_transitions;

	CTransition					m_currentTransition;
	State						m_state = State::LLCheck;
	bool						m_result = true;
};

