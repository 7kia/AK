#pragma once

#include <memory>
#include <string>
#include <vector>
#include "../Lexer/Token.h"

class IRuleElement
{
public:
	enum class Type
	{
		NotTerminal
		, Terminal
	};

	IRuleElement(Type type)
		: m_type(type)
	{

	};

	virtual ~IRuleElement() = default;

	Type m_type;
};

using PRuleElement = std::shared_ptr<IRuleElement>;
using RuleElements = std::vector<PRuleElement>;

class NotTerminal : public IRuleElement
{
public:
	NotTerminal(const std::string & name, const std::vector<RuleElements> & ruleElements);
//////////////////////////////////////////////////////////////////////
// Methods
public:
	std::string					m_name;
	std::vector<RuleElements>	m_ruleElements;
};

class Terminal : public IRuleElement
{
public:
	Terminal(const TokensId & token);
//////////////////////////////////////////////////////////////////////
// Methods
public:
	bool		Recognize(const TokensId & tokenId);

//////////////////////////////////////////////////////////////////////
// Data
public:
	TokensId		m_tokenId;// For return value, need to semantic(AST)
};

using PTerminal = std::shared_ptr<Terminal>;
using PNotTerminal = std::shared_ptr<NotTerminal>;

//////////////////////////////////////////////////////////////////////
// Exceptions
class CUnexpectedSymbolsError : public std::runtime_error
{
public:
	CUnexpectedSymbolsError(const TokensId & tokenId, const TokensId & expectedTokenId)
		: runtime_error("Expected " + TokensStringPresentation.at(expectedTokenId)
			+ ".Gived " + TokensStringPresentation.at(tokenId) + ".\n")
	{}
};
