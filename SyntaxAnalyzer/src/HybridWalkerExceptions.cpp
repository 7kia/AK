#include "stdafx.h"
#include "HybridWalkerExceptions.h"

namespace
{

	std::string GetSequenceSymbol(const std::vector<CLRRowElement> & expectedSym)
	{
		std::string expectedSymbols;
		if (expectedSym.size() > 0)
		{
			for (size_t i = 0; i < expectedSym.size(); i++)
			{
				if (expectedSym[i].m_transition.m_index != -1 || expectedSym[i].m_rollup)
				{
					expectedSymbols += expectedSym[i].m_inputToken.value;
					if (i + 1 < expectedSym.size())
					{
						expectedSymbols += "|";
					}
				}
			}
		}

		return expectedSymbols;
	};

	// TODO : see need reload
	std::string GetSequenceSymbol(const std::vector<SToken> & expectedSym)
	{
		std::string expectedSymbols;
		if (expectedSym.size() > 0)
		{
			for (size_t i = 0; i < expectedSym.size(); i++)
			{
				expectedSymbols += expectedSym[i].value;
				if (i + 1 < expectedSym.size())
				{
					expectedSymbols += "|";
				}
			}
		}

		return expectedSymbols;
	}
};


CUnexpectedSymbolsError::CUnexpectedSymbolsError(const std::vector<CLRRowElement>& expectedSym
	, const std::string & unexpectedSym
	, size_t index)
	: std::runtime_error("Error. Expected [" 
		+ GetSequenceSymbol(expectedSym) 
		+ "] but (" + unexpectedSym 
		+ "[" + std::to_string(index + 1) + "]" + ") was given!")
{
}

CNoTransitionError::CNoTransitionError(const std::vector<CLRRowElement>& noTransitionRuleSequence)
	: std::runtime_error("No transition from ["
		+ GetSequenceSymbol(noTransitionRuleSequence) + "]")
{
}

CLLUnexpectedSymbolsError::CLLUnexpectedSymbolsError(const std::vector<SToken>& expectedSym
												, const SToken & unexpectedSym
												, size_t index)
	: std::runtime_error("Error. Expected [" + GetSequenceSymbol(expectedSym)
		+ "] but (" + unexpectedSym.value 
		+ "[" + std::to_string(index + 1) + "]" + ") was given!")
{
}

CLLNoTransitionError::CLLNoTransitionError(const std::vector<SToken>& noTransitionRuleSequence)
	: runtime_error("No transition from [" + GetSequenceSymbol(noTransitionRuleSequence) + "]")
{
}