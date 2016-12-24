#include "stdafx.h"


#include "Interpreter.h"

#include <iostream>
#include <time.h>

#include "main.h"

using namespace std;

void CheckParametrs(int argc)
{
	if (argc != AMOUNT_ARGUMENTS)
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS));
	}
}

///////////////////////////////////////////////
// TODO : transfer to other place

bool ToRecognizeTerminal(Terminal* terminal, const SToken & token)
{
	if (terminal->m_tokenId == token.id)
	{
		//return std::make_shared<RecognizeTerminal>(token);
		return true;
	}

	//throw CUnexpectedSymbolsError(token.id, terminal->m_tokenId);
	return false;
}

// TODO : transfer to other place
///////////////////////////////////////////////



int main(int argc, char *argv[]) 
{
	//Add ToRecognizeTerminal, check it work

	/*
	try
	{
		CheckParametrs(argc);
	}
	catch (const std::invalid_argument& e)
	{
		(void)e;

		CInterpreter interpreter(std::cout);

		interpreter.EnterLoop(std::cin);

		return 0;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		return 1;
	}
    

	ofstream outputFile(argv[2]);
	ifstream inputFile(argv[1]);

	CInterpreter interpreter(outputFile);
	interpreter.EnterLoop(inputFile);
	*/
	PTerminal Id = std::make_shared<Terminal>(TokensId::TK_ID);
	PTerminal Plus = std::make_shared<Terminal>(TokensId::TK_PLUS);

	NotTerminal Axiom("Axiom", {
		{ Id }
		, { Id , Plus , Id }
	});

	std::vector<SToken> tokens = { SToken("id", TokensId::TK_ID)
								, SToken("+", TokensId::TK_PLUS)
								, SToken("id", TokensId::TK_ID) };
	
	auto inputToken = SToken("id", TokensId::TK_ID);
	auto pTerminal = dynamic_cast<Terminal*>(Axiom.m_ruleElements[0][0].get());
	bool isRecognize = ToRecognizeTerminal(pTerminal
											, inputToken);

	inputToken = SToken("+", TokensId::TK_PLUS);
	bool isRecognize2 = ToRecognizeTerminal(pTerminal
		, inputToken);

    return 0;
}
