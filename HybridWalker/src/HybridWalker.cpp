#include "stdafx.h"
#include "HybridWalker.h"
#include "HybridWalkerExceptions.h"


HybridWalker::HybridWalker(const Tokens & tokens, const LRTable & LRtable)
	: m_LRtable(LRtable)
	, m_inputTokens(tokens)
{}

bool HybridWalker::CheckInputSequence()
{
	m_transitions.push(CTransition(0u, &m_LRtable, CTransition::TypeTable::LR));// First transitionIndex - it is axiom
	size_t startSize = m_inputTokens.size();
	while (!m_transitions.empty())
	{
		for (size_t i = 0; i < m_LRtable[m_transitions.top().m_index].size(); i++)
		{
			if (m_inputTokens.empty())
			{
				//////////////////////////////////////////////////////////
				// Rollup - ������
				if (m_LRtable[m_transitions.top().m_index].back().m_rollup)
				{
					auto rule = *m_LRtable[m_transitions.top().m_index].back().m_rollup;
					// Clear stack
					for (size_t j = 0; j < rule.size; j++)
					{
						m_transitions.pop();
						m_elements.pop();
					}
					// Add the rule
					m_inputTokens.push_back(rule.outputSym);
					m_elements.push(rule.outputSym);
					break;
				}
				//////////////////////////////////////////////////////////
				else
				{
					throw CUnexpectedSymbolsError(m_LRtable[m_transitions.top().m_index], "", startSize - m_inputTokens.size());
				}
			}
			else
			{
				auto currentTransition = m_LRtable[m_transitions.top().m_index][i];
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
						m_inputTokens.insert(m_inputTokens.begin(), rule.outputSym);
						m_elements.push(rule.outputSym);
					}
					//////////////////////////////////////////////////////////
					else
					{
						throw CUnexpectedSymbolsError(m_LRtable[m_transitions.top().m_index], m_inputTokens.front(), startSize - m_inputTokens.size());
					}
					break;
				}
				//////////////////////////////////////////////////////////
				// Not found correspond rules
				if (i >= m_LRtable[m_transitions.top().m_index].size() - 1)
				{
					throw CUnexpectedSymbolsError(m_LRtable[m_transitions.top().m_index], m_inputTokens.front(), startSize - m_inputTokens.size());
				}
			}
		}
	}
	return true;
}