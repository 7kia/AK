#include "stdafx.h"


#include "Interpreter.h"
#include "StringPool.h"
#include "InterpreterContext.h"
#include "Parser.h"
#include "Lexer.h"
#include "Grammar.h"


using std::bind;
using namespace std::placeholders;


class CInterpreter::Impl
{
public:
    void ConsumeLine(std::string const& line)
    {
        CLexer lexer(line);

        SToken token;
		TokensId tokenId;
        do
        {
			tokenId = lexer.Scan(token);
		} 
		while (tokenId != TokensId::TK_NONE);
    }
private:

};

CInterpreter::CInterpreter(std::ostream &output)
    : m_pImpl(new Impl(output))
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
        if (!m_pImpl->ConsumeLine(line))
        {
            return;
        }
    }
}
