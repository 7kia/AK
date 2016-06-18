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
		if (!input.eof())
		{
			line += NEWLINE_SYMBOL;
		}
		ProcessLine(line);
    }
}

void CInterpreter::ProcessLine(const std::string & line)
{
	CLexer lexer(line);

	TokensId tokenId;
	do
	{
		tokenId = lexer.Scan(m_token);
		//token.id = tokenId;// TODO : see need tokenId
		// Добавлено для читаемости тестов
		if ( (tokenId == TokensId::TK_NONE) 
			|| (tokenId == TokensId::TK_NEWLINE)
			)// TODO : process errors, now print nothing
		{
			m_output << std::endl;
		}
		else
		{
			m_output << m_token.value << " - " << TokensStringPresentation.at(tokenId) << std::endl;
		}

	} while ( (tokenId != TokensId::TK_NONE) 
				&& (tokenId != TokensId::TK_NEWLINE)
				&& (!lexer.IsEndLine())
			);// TODO: might need TK_NONE
}
