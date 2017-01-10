#include "stdafx.h"
#include "HybridWalker.h"
#include "Transition.h"

CTransition::CTransition(size_t index, LRTable * pLRTable)
	: m_index(index)
	, m_pLRTable(pLRTable)
{
}
