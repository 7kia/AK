#pragma once

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

using RuleElements = std::vector<IRuleElement>;

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
private:
	TokensId		m_tokenId;// For return value, need to semantic(AST)
};

///////////////////////////////////////////////////////////////////////
// Recognize terminal and not terminal
class IRecognizeElement
{
public:
	enum class Type
	{
		NotTerminal
		, Terminal
	};

	IRecognizeElement(Type type)
		: m_type(type)
	{

	};

	virtual ~IRecognizeElement() = default;

	Type m_type;
};

using RecognizeElements = std::vector<IRecognizeElement>;

class RecognizeNotTerminal : public IRecognizeElement
{
public:
	RecognizeNotTerminal();
	//////////////////////////////////////////////////////////////////////
	// Methods
public:
	std::string			m_name;// TODO : see need it
	RecognizeElements	m_recognizeElements;
};

class RecognizeTerminal : public IRecognizeElement
{
public:
	RecognizeTerminal();
	//////////////////////////////////////////////////////////////////////
	// Methods
public:
	//////////////////////////////////////////////////////////////////////
	// Data
public:
	SToken		m_token;// For return value, need to semantic(AST)
};