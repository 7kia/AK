// $Id: exprtest.cc 18 2007-08-19 19:51:52Z tb $
#include "stdafx.h"

#include <iostream>
#include <fstream>

#include "main.h"
#include "src/driver.h"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != AMOUNT_ARGUMENTS)
	{
		return 1;
	}

	std::ifstream	inputFile;
	std::ofstream	outFile;
	std::ofstream	idsFile;

	inputFile.open(argv[1]);
	outFile.open(argv[2]);
	idsFile.open(argv[3]);

	//example::CCompilerDriver driver(outFile, outFile, idsFile);
	//bool readfile = false;

	//Tests/Syntax/Comments.txt Tests/OutputSyntax/OutputIdComments.txt  Tests/OutputSyntax/OutputComments.txt

	
	std::srand(static_cast<unsigned>(time(nullptr)));
	example::CCompilerDriver driver(outFile, outFile, idsFile);

	if (!driver.Compile(inputFile, "program.obj"))
	{
		return 1;
	}

	return 0;
}
