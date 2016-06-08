#include "stdafx.h"
#include "FunctionsForTests.h"

using namespace std;

void CompareFiles(const string & first, const string & second)
{
	ifstream resultFile(first);
	ifstream rightResultFile(second);

	istream_iterator<char> iterResultFile(resultFile), endIter;
	istream_iterator<char> iterRightRsultFile(rightResultFile);

	BOOST_CHECK_EQUAL_COLLECTIONS(iterResultFile, endIter, iterRightRsultFile, endIter);
}

void TestLexer(const std::string nameInputFile
				, const std::string nameErrorFile
				, const std::string nameOutputFile)
{
	ofstream outputFile(nameOutputFile);
	ofstream errorFile(nameErrorFile);
	ifstream inputFile(nameInputFile);

	CInterpreter interpreter(outputFile, errorFile);
	interpreter.EnterLoop(inputFile);
};
