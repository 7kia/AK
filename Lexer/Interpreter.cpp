#include "stdafx.h"


#include "Interpreter.h"
#include "Lexer.h"
#include "Grammar.h"

CInterpreter::CInterpreter()
{
}

CInterpreter::~CInterpreter()
{
}

void CInterpreter::EnterLoop(std::istream &input)
{
    std::string line;
    while (std::getline(input, line))
    {
		ProcessLine(line);
    }
}

void CInterpreter::ProcessLine(const std::string & line)
{
	CLexer lexer(line);

	SToken token;
	TokensId tokenId;
	do
	{
		tokenId = lexer.Scan(token);
	} while (tokenId != TokensId::TK_NONE);
}
