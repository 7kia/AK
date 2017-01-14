#include "stdafx.h"
#include "RecognizeUnits.h"

RecognizeNotTerminal::RecognizeNotTerminal()
	: IRecognizeElement(Type::NotTerminal)
{
}

RecognizeTerminal::RecognizeTerminal(const SToken & token)
	: IRecognizeElement(Type::Terminal)
	, m_token(token)
{
}

