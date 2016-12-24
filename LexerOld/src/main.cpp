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



int main(int argc, char *argv[]) 
{
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
	Terminal Id(TokensId::TK_ID);
	Terminal Plus(TokensId::TK_PLUS);

	NotTerminal Axiom("Axiom", {
		{ Id }
		, { Id , Plus , Id }
	});



    return 0;
}
