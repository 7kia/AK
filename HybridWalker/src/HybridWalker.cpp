#include "stdafx.h"
#include "HybridWalker.h"
#include "HybridWalkerExceptions.h"


namespace
{
	bool CheckSymbolInInput(const std::string & currentSymbol, const std::vector<std::string> & inputSet)
	{
		return std::find(inputSet.begin(), inputSet.end(), currentSymbol) != inputSet.end();
	}
}

HybridWalker::HybridWalker(const LRTable & LRtable
							, const LLTable & LLtable
							, State state)
	: m_LRTable(LRtable)
	, m_LLTable(LLtable)
	, m_state(state)
	, m_currentTransition(0, &m_LLTable, CTransition::TypeTable::LL)

{
}

bool HybridWalker::CheckInputSequence(const Tokens & tokens)
{
	m_inputTokens = tokens;

	if (m_state == State::LLCheck)
	{
		m_transitions.push(CTransition(0u, &m_LLTable, CTransition::TypeTable::LL));// First transitionIndex - it is axiom
		m_currentTransition = CTransition(0, &m_LLTable, CTransition::TypeTable::LL);
		return CheckAsLL();
	}
	else if (m_state == State::LRCheck)
	{
		m_transitions.push(CTransition(0u, &m_LRTable, CTransition::TypeTable::LR));// First transitionIndex - it is axiom
		m_currentTransition = CTransition(0, &m_LRTable, CTransition::TypeTable::LR);// TODO : see need it there
		return CheckAsLR();
	}

	throw std::runtime_error("Incorrect start state");
}

bool HybridWalker::CheckAsLR()
{
	size_t startSize = m_inputTokens.size();
	while (!m_transitions.empty())
	{
		size_t index = m_transitions.top().m_index;

		if (m_transitions.top().m_tableType == CTransition::TypeTable::LL)
		{
			index = m_currentTransition.m_index;
		}

		for (size_t i = 0; i < m_LRTable[index].size(); i++)
		{
			if (m_inputTokens.empty())
			{
				//////////////////////////////////////////////////////////
				// Rollup - ������
				if (m_LRTable[m_transitions.top().m_index].back().m_rollup)
				{
					auto rule = *m_LRTable[m_transitions.top().m_index].back().m_rollup;
					// Clear stack
					for (size_t j = 0; j < rule.size; j++)
					{
						m_transitions.pop();
						m_elements.pop();
					}
					// Add the rule
					m_inputTokens.push_back(rule.nameRule);
					m_elements.push(rule.nameRule);

					// TODO : see need it there
					m_currentTransition = m_transitions.top();
					// Trabsition
					if (m_currentTransition.m_tableType == CTransition::TypeTable::LL)
					{
						m_state = State::LLCheck;
						m_result = CheckAsLL();
					}

					break;
				}
				//////////////////////////////////////////////////////////
				else
				{
					throw CUnexpectedSymbolsError(m_LRTable[m_transitions.top().m_index], "", startSize - m_inputTokens.size());
				}
			}
			else
			{
				auto currentTransition = m_LRTable[index][i];

				// Trabsition
				if (currentTransition.m_transition.m_tableType == CTransition::TypeTable::LL)
				{
					m_state = State::LLCheck;
					m_result = CheckAsLL();
				}
				//////////////////////////////////////////////////////////
				// Find correspond
				if (currentTransition.m_inputSymbol == m_inputTokens.front())
				{
					// Is transitionIndex
					if (currentTransition.m_transition.m_index != -1)
					{
						m_transitions.push(currentTransition.m_transition);
						// Add element and delete recognize element from input line
						if (currentTransition.m_isShift)
						{
							m_elements.push(m_inputTokens.front());
						}
						m_inputTokens.erase(m_inputTokens.begin());
						// Trabsition
						if (m_currentTransition.m_tableType == CTransition::TypeTable::LL)
						{
							m_state = State::LLCheck;
							m_result = CheckAsLL();
						}
					}
					// End
					else if (currentTransition.m_isShift && currentTransition.m_inputSymbol == "S")
					{
						return true;
					}
					//////////////////////////////////////////////////////////
					// Rollup - ������
					else if (currentTransition.m_rollup)
					{
						auto rule = *currentTransition.m_rollup;
						// Clear stack and push the rule
						for (size_t j = 0; j < rule.size; j++)
						{
							m_transitions.pop();
							m_elements.pop();
						}
						m_inputTokens.insert(m_inputTokens.begin(), rule.nameRule);
						m_elements.push(rule.nameRule);

						// TODO : see need it there
						m_currentTransition = m_transitions.top();
						// Trabsition
						if (m_currentTransition.m_tableType == CTransition::TypeTable::LL)
						{
							m_state = State::LLCheck;
							m_result = CheckAsLL();
						}
					}
					//////////////////////////////////////////////////////////
					else
					{
						throw CUnexpectedSymbolsError(m_LRTable[index], m_inputTokens.front(), startSize - m_inputTokens.size());
					}
					break;
				}
				//////////////////////////////////////////////////////////
				// Not found correspond rules
				if (i >= (m_LRTable[index].size() - 1))
				{
					throw CUnexpectedSymbolsError(m_LRTable[index], m_inputTokens.front(), startSize - m_inputTokens.size());
				}
			}
		}
	}

	m_state = State::End;
	return m_result;
}

bool HybridWalker::CheckAsLL()
{
	size_t currentSymbolIndex = 0;
	size_t startSize = m_inputTokens.size();
	size_t & tableRowIndex = m_currentTransition.m_index;
	CLL1RowElement currentTableRow = m_LLTable[tableRowIndex];
	std::string currentSymbol = m_inputTokens[currentSymbolIndex];

	for (; !(m_LLTable[tableRowIndex].m_end && (currentSymbolIndex == startSize - 1));
		currentTableRow = m_LLTable[tableRowIndex], currentSymbol = m_inputTokens[0])
	{
		if (CheckSymbolInInput(currentSymbol, currentTableRow.m_input))
		{
			if (currentTableRow.m_shift)
			{
				currentSymbolIndex++;
				m_inputTokens.erase(m_inputTokens.begin());
			}

			if (currentTableRow.m_stack)
			{
				m_transitions.push(CTransition(tableRowIndex + 1, &m_LLTable, CTransition::TypeTable::LL));
			}

			
			m_currentTransition = GetCurrentTransition(currentTableRow);
			if (m_currentTransition.m_tableType == CTransition::TypeTable::LR)
			{
				m_state = State::LRCheck;
				m_result = CheckAsLR();
			}
		}
		else if (!currentTableRow.m_error)
		{
			tableRowIndex++;
		}
		else
		{
			throw CLLUnexpectedSymbolsError(m_LLTable[tableRowIndex].m_input, currentSymbol, currentSymbolIndex);
		}
	}
	/*
		if (m_state == State::LLCheck)
	{
		m_result = CheckAsLL();
	}

	*/

	m_state = State::End;
	return m_result;
}

CTransition HybridWalker::GetCurrentTransition(const CLL1RowElement & row)
{
	if (row.m_transition.m_index != -1)
	{
		return row.m_transition;
	}
	else if (!m_transitions.empty())
	{
		CTransition topStack = m_transitions.top();
		m_transitions.pop();
		return topStack;
	}
	else
	{
		throw CLLNoTransitionError(row.m_input);
	}
}

void HybridWalker::SetState(State state)
{
	m_state = state;
}
