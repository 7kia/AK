#include "stdafx.h"
#include "HybridWalker.h"
#include "Transition.h"

#include "LL1Walker.h"

CTransition::CTransition(size_t index)
	: m_index(index)
{
}

CTransition::CTransition(size_t index
						, void * pTable
						, CTransition::TypeTable type)
	: m_index(index)
	, m_tableType(type)
	, m_pTable(pTable)
{
}


CTransition::CTransition(const CTransition & copy)
	: m_index(copy.m_index)
	, m_pTable(copy.m_pTable)
{
}

LRTable & PointerConverter::GetLRTable(CTransition & transition)
{
	CheckTablePointer(transition);

	if (transition.m_tableType != CTransition::TypeTable::LR)
	{
		throw std::runtime_error("The table is not LR");
	}

	return *static_cast<LRTable*>(transition.m_pTable);
}

LL1Table & PointerConverter::GetLLTable(CTransition & transition)
{
	CheckTablePointer(transition);

	if (transition.m_tableType != CTransition::TypeTable::LL)
	{
		throw std::runtime_error("The table is not LL");
	}

	return *static_cast<LL1Table*>(transition.m_pTable);
}

void PointerConverter::CheckTablePointer(CTransition & transition)
{
	if (transition.m_pTable == nullptr)
	{
		throw std::runtime_error("Table not define");
	}
}

/*
CTransition & CTransition::operator=(const CTransition & other)
{
	m_index = other.m_index;
	m_pLLTable = other.m_pLLTable;
	m_pLRTable = other.m_pLRTable;

	return *this;
}
*/