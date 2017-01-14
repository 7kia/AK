#include "stdafx.h"
#include "Rule.h"

NotTerminal::NotTerminal(const std::string & name, const std::vector<RuleElements> & ruleElements)
	: IRuleElement(Type::NotTerminal)
	, m_name(name)
	, m_ruleElements(ruleElements)
{
}

Terminal::Terminal(const TokensId & token)
	: IRuleElement(Type::Terminal)
	, m_tokenId(token)
{
}

bool Terminal::Recognize(const TokensId & tokenId)
{
	if (tokenId == m_tokenId)
	{
		return true;
	}

	// TODO : see might need own type exception
	throw CUnexpectedSymbolsError(tokenId, m_tokenId);

	return false;
}
