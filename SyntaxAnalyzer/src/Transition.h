#pragma once

#include "Lexer\Token.h"
#include "LRRow.h"


class CTransition
{
public:
	CTransition(size_t index);

	enum class TypeTable
	{
		LL = 0
		, LR
		, NONE
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
	TypeTable		m_tableType = TypeTable::NONE;
	size_t			m_index = 0;
	void *			m_pTable = nullptr;
};
class CLL1RowElement
{
public:
	CLL1RowElement(const std::vector<SToken> & input
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
	std::vector<SToken> m_input;
};

class CLRRowElement
{
public:
	CLRRowElement(const SToken & sym
		, CTransition transition
		, bool shift);
	CLRRowElement(const SToken & sym
		, CTransition transition
		, Rule rule
		, bool shift);
	//////////////////////////////////////////////////////////////////////
	// Data
public:
	SToken					m_inputToken;
	CTransition				m_transition;
	boost::optional<Rule>	m_rollup;
	bool					m_isShift;
};


using LLTable = std::vector<CLL1RowElement>;
using LRTable = std::vector<std::vector<CLRRowElement>>;

namespace PointerConverter
{
	LRTable & GetLRTable(CTransition & transition);
	LLTable & GetLLTable(CTransition & transition);

	void	CheckTablePointer(CTransition & transition);
}

// Ready transitions
static const CTransition notLLTransition(-1, nullptr, CTransition::TypeTable::LL);
static const CTransition notLRTransition(-1, nullptr, CTransition::TypeTable::LR);
