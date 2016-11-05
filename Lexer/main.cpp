// $Id: exprtest.cc 18 2007-08-19 19:51:52Z tb $
#include "stdafx.h"

#include <iostream>
#include <fstream>

#include "main.h"
#include "src/driver.h"
#include "src/expression.h"
#include "src/Compile.h"

// TODO : rewrite without FILE

void ParseFile(const char* inputFileName, const char* outputFileName, const char* outputIdFileName)
{
	//yyOutId.open(outputIdFileName);
	//yyout.open(outputFileName);

	//::yyin.open(inputFileName);
}

int main(int argc, char *argv[])
{
	CalcContext calc;
	example::Driver driver(calc);
	bool readfile = false;

	//Tests/Syntax/Comments.txt Tests/OutputSyntax/OutputIdComments.txt  Tests/OutputSyntax/OutputComments.txt

	if (argc != AMOUNT_ARGUMENTS)
	{
		return 1;
	}

	ParseFile(argv[1], argv[2], argv[3]);
	driver.parse_file(argv[1], argv[2], argv[3]);
	/*
		for (int ai = 1; ai < argc; ++ai)
	{
		if (argv[ai] == std::string("-p"))
		{
			driver.trace_parsing = true;
		}
		else if (argv[ai] == std::string("-s"))
		{
			driver.trace_scanning = true;
		}
		else
		{
			// read a file with expressions

			if (!yyin.good())
			{
				std::cerr << "Could not open file: " << argv[ai] << std::endl;
				return 0;
			}

			calc.clearExpressions();
			bool result = driver.parse_stream(yyin, argv[ai]);
			if (result)
			{
				std::cout << "Expressions:" << std::endl;
				for (unsigned int ei = 0; ei < calc.expressions.size(); ++ei)
				{
					std::cout << "[" << ei << "]:" << std::endl;
					std::cout << "tree:" << std::endl;
					calc.expressions[ei]->print(std::cout);
					std::cout << "evaluated: "
						<< calc.expressions[ei]->evaluate()
						<< std::endl;
				}
			}

			readfile = true;
		}
	}

	if (readfile) return 0;

	std::cout << "Reading expressions from stdin" << std::endl;

	std::string line;
	while (std::cout << "input: " &&
		std::getline(std::cin, line) &&
		!line.empty())
	{
		calc.clearExpressions();
		bool result = driver.parse_string(line, "input");

		if (result)
		{
			for (unsigned int ei = 0; ei < calc.expressions.size(); ++ei)
			{
				std::cout << "tree:" << std::endl;
				calc.expressions[ei]->print(std::cout);
				std::cout << "evaluated: "
					<< calc.expressions[ei]->evaluate()
					<< std::endl;
			}
		}
	}

	*/

	return 0;
}
