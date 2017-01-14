#pragma once

#include "Rule.h"

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
	RecognizeTerminal(const SToken & token);
	//////////////////////////////////////////////////////////////////////
	// Methods
public:
	//////////////////////////////////////////////////////////////////////
	// Data
public:
	SToken		m_token;// For return value, need to semantic(AST)
};

using PRecognizeTerminal = std::shared_ptr<RecognizeTerminal>;
using PRecognizeNotTerminal = std::shared_ptr<RecognizeNotTerminal>;
