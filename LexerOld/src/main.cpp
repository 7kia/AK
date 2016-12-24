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
		return true;
	}

	return false;
}

bool ToRecognizeNotTerminal(NotTerminal* terminal, std::vector<SToken> & tokenStack)
{
	bool result = true;
	bool equalThisRule = true;
	size_t index = 0;
	for (const auto ruleLine : terminal->m_ruleElements)
	{
		for (const auto element : ruleLine)
		{
			auto typeElement = element->m_type;

			////////////////////
			// Check element rule
			if (typeElement == IRuleElement::Type::NotTerminal)
			{
				equalThisRule = ToRecognizeNotTerminal(dynamic_cast<NotTerminal*>(element.get()), tokenStack);
				if (!equalThisRule)
				{
					index = 0;
					break;
				}
			}
			else
			{
				equalThisRule = ToRecognizeTerminal(dynamic_cast<Terminal*>(element.get()), tokenStack[index++]);
				if (!equalThisRule)
				{
					index = 0;
					break;
				}
			}
		}
		////////////////////

		if (equalThisRule)
		{
			break;
		}
	}


	return equalThisRule;
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
	PTerminal Integer = std::make_shared<Terminal>(TokensId::TK_INTEGER);


	const std::vector<RuleElements> vector =  {
				{ Id , Plus , Id }
			,	{ Integer , Plus , Id }
			,	{ Id , Plus , Integer }
			,	{ Id }

	};
	PNotTerminal Axiom = std::make_shared<NotTerminal>(
		"Axiom"
		, vector
		);

	std::vector<SToken> tokens = { SToken("id", TokensId::TK_ID)
								, SToken("+", TokensId::TK_PLUS)
								, SToken("id", TokensId::TK_ID) };
	
	/*
		auto inputToken = SToken("id", TokensId::TK_ID);
	auto pTerminal = dynamic_cast<Terminal*>(Axiom.m_ruleElements[0][0].get());
	bool isRecognize = ToRecognizeTerminal(pTerminal
											, inputToken);

	inputToken = SToken("+", TokensId::TK_PLUS);
	bool isRecognize2 = ToRecognizeTerminal(pTerminal
		, inputToken);


	*/

	//auto pNotTerminal = dynamic_cast<NotTerminal*>(Axiom.m_ruleElements[0][0].get());
	//bool isRecognize = ToRecognizeNotTerminal(Axiom.get(), tokens);

	tokens = { SToken("2", TokensId::TK_INTEGER)
		, SToken("+", TokensId::TK_PLUS)
		, SToken("id", TokensId::TK_ID) };
	bool isRecognize2 = ToRecognizeNotTerminal(Axiom.get(), tokens);


    return 0;
}
