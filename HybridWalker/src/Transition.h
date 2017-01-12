#pragma once

#include "LRRow.h"


class CTransition
{
public:
	CTransition(size_t index);

	enum class TypeTable
	{
		LL = 0
		, LR
	};


	CTransition(size_t index
		, void * pTable
		, CTransition::TypeTable type);

	CTransition(const CTransition & copy);
	//////////////////////////////////////////////////////////////////////
	// Methods
public:

private:
	//////////////////////////////////////////////////////////////////////
	// Data
public:
	TypeTable		m_tableType = TypeTable::LL;
	size_t			m_index = 0;
	void *			m_pTable = nullptr;
};
class CLL1RowElement
{
public:
	CLL1RowElement(const std::vector<std::string> & input
		, bool shift
		, CTransition transition
		, bool stack
		, bool error
		, bool end);
	//////////////////////////////////////////////////////////////////////
	// Data
public:
	CTransition m_transition;
	bool m_error;
	bool m_shift;
	bool m_end;
	bool m_stack;
	std::vector<std::string> m_input;
};

class CLRRowElement
{
public:
	CLRRowElement(const std::string & sym
		, CTransition transition
		, bool shift);
	CLRRowElement(const std::string & sym
		, CTransition transition
		, Rule rule
		, bool shift);
	//////////////////////////////////////////////////////////////////////
	// Data
public:
	std::string				m_inputSymbol = "";
	CTransition				m_transition;
	boost::optional<Rule>	m_rollup;
	bool					m_isShift;
};


using LL1Table = std::vector<CLL1RowElement>;
using LRTable = std::vector<std::vector<CLRRowElement>>;

namespace PointerConverter
{
	LRTable & GetLRTable(CTransition & transition);
	LL1Table & GetLLTable(CTransition & transition);

	void	CheckTablePointer(CTransition & transition);
}