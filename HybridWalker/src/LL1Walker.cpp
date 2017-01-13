#include "stdafx.h"
#include "LL1Walker.h"
#include "Transition.h"

namespace
{
	bool CheckSymbolInInput(const std::string & currentSymbol, const std::vector<std::string> & inputSet)
	{
		return std::find(inputSet.begin(), inputSet.end(), currentSymbol) != inputSet.end();
	}

	std::string GetSequenceSymbol(const std::vector<std::string> & expectedSym)
	{
		std::string expectedSymbols;
		if (expectedSym.size() > 0)
		{
			for (size_t i = 0; i < expectedSym.size(); i++)
			{
				expectedSymbols += expectedSym[i];
				if (i + 1 < expectedSym.size())
				{
					expectedSymbols += "|";
				}
			}
		}

		return expectedSymbols;
	}
}

class CLLUnexpectedSymbolsError : public std::runtime_error
{
public:
	CLLUnexpectedSymbolsError(const std::vector<std::string>& expectedSym, const std::string & unexpectedSym, size_t index)
		: runtime_error("Error. Expected [" + GetSequenceSymbol(expectedSym) + "] but (" + unexpectedSym +"[" + std::to_string(index + 1) + "]" + ") was given!")
	{}
};

class CLLNoTransitionError : public std::runtime_error
{
public:
	CLLNoTransitionError(const std::vector<std::string>& noTransitionRuleSequence)
		: runtime_error("No transition from [" + GetSequenceSymbol(noTransitionRuleSequence) + "]")
	{}
};

LL1Walker::LL1Walker(const LLTable & table)
	: m_LLTable(table)
{
}

bool LL1Walker::CheckInputSequence(const std::vector<std::string>& inputStr)
{
	size_t currentSymbolIndex = 0;
	CTransition currentTransition(0, &m_LLTable, CTransition::TypeTable::LL);
	size_t & tableRowIndex = currentTransition.m_index;
	CLL1RowElement currentTableRow = m_LLTable[tableRowIndex];
	std::string currentSymbol = inputStr[currentSymbolIndex];

	for (;!(m_LLTable[tableRowIndex].m_end && (currentSymbolIndex == inputStr.size() - 1));
		currentTableRow = m_LLTable[tableRowIndex], currentSymbol = inputStr[currentSymbolIndex])
	{
		if (CheckSymbolInInput(currentSymbol, currentTableRow.m_input))
		{
			if (currentTableRow.m_shift)
			{
				currentSymbolIndex++;
			}

			if (currentTableRow.m_stack)
			{
				m_transitions.push(CTransition(tableRowIndex + 1, &m_LLTable, CTransition::TypeTable::LL));
			}

			currentTransition = GetCurrentTransition(currentTableRow);
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

	return true;
}

CTransition LL1Walker::GetCurrentTransition(const CLL1RowElement & row)
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
