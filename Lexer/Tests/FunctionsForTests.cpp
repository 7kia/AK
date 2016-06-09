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

void RunLexer(const std::string nameInputFile, const std::string nameOutputFile)
{
	ofstream outputFile(nameOutputFile);
	ifstream inputFile(nameInputFile);

	CInterpreter interpreter(outputFile);
	interpreter.EnterLoop(inputFile);
}

void TestLexer(const std::string & suffixNametest)
{
	const std::string suffixCheckFiles = suffixNametest + TestNameFiles::nameFormatFiles;

	BOOST_REQUIRE_NO_THROW(RunLexer(TestNameFiles::nameCodeFile + suffixCheckFiles
									, TestNameFiles::nameOutputFile + suffixCheckFiles));

	CompareFiles(TestNameFiles::nameOutputFile + suffixCheckFiles
		, PATH_RIGHT_DATA + TestNameFiles::nameOutputFile + suffixCheckFiles);

};
