#include "stdafx.h"


#include "Interpreter.h"
#include "Lexer.h"
#include "Grammar.h"

CInterpreter::CInterpreter(std::ostream &output)
	: m_output(output)
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

		// Добавлено для читаемости тестов
		if (tokenId == TokensId::TK_NONE)// TODO : process errors, now print nothing
		{
			m_output << std::endl;
		}
		else
		{
			m_output << token.value << " - " << TokensStringPresentation.at(tokenId) << std::endl;
		}

	} while (tokenId != TokensId::TK_NONE);// TODO: might need TK_NONE
}
