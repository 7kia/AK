#include "stdafx.h"
#include "Transition.h"

CLL1RowElement::CLL1RowElement(const std::vector<SToken> & input
							, bool shift
							, CTransition transition
							, bool stack
							, bool error
							, bool end)
	: m_transition(transition)
	, m_error(error)
	, m_shift(shift)
	, m_end(end)
	, m_input(input)
	, m_stack(stack)
{
}