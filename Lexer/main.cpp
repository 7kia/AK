// $Id: exprtest.cc 18 2007-08-19 19:51:52Z tb $
#include "stdafx.h"

#include <iostream>
#include <fstream>

#include "main.h"
#include "src/driver.h"
#include "src/AST.h"

int main(int argc, char *argv[])
{
	CAST calc;
	example::Driver driver(calc);
	bool readfile = false;

	//Tests/Syntax/Comments.txt Tests/OutputSyntax/OutputIdComments.txt  Tests/OutputSyntax/OutputComments.txt

	if (argc != AMOUNT_ARGUMENTS)
	{
		return 1;
	}

	driver.parse_file(argv[1], argv[2], argv[3]);

	return 0;
}
