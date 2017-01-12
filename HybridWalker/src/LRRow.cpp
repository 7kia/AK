#include "stdafx.h"
#include "Transition.h"


CLRRowElement::CLRRowElement(const std::string & sym
	, CTransition transition
	, bool shift)
	: m_inputSymbol(sym)
	, m_transition(transition)
	, m_isShift(shift)
{
}

CLRRowElement::CLRRowElement(const std::string & sym
	, CTransition transition
	, Rule rule
	, bool shift)
	: m_inputSymbol(sym)
	, m_transition(transition)
	, m_rollup(rule)
	, m_isShift(shift)
{
}