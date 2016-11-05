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

void RunLexer(const std::string &inputFileName
			, const std::string &outputFileName
			, const std::string &outputIdFileName)
{
	CalcContext calc;
	example::Driver driver(calc);
	driver.parse_file(inputFileName, outputFileName, outputIdFileName);
}

std::string	GetAbsolutePath(const std::string & name
							, const std::string & folder
							, const std::string & prefix
							, const std::string & prefixName)

{
	std::string result;

	if (!folder.empty())
	{
		result = prefix + folder + "/";
	}
	result += prefix + prefixName + name + TestNameFiles::nameFormatFiles;

	return result;
}


void TestLexer(const std::string & nameFile, const std::string & folder)
{
	
	std::string nameInputFile = GetAbsolutePath(nameFile, folder, "", "");
	std::string nameOutputFile = GetAbsolutePath(nameFile, folder, TestNameFiles::nameOutputFile, "");
	std::string nameOutputIdsFile = GetAbsolutePath(nameFile, folder, TestNameFiles::nameOutputFile, "Id");

	BOOST_REQUIRE_NO_THROW(RunLexer(nameInputFile, nameOutputFile, nameOutputIdsFile));

	std::string nameRightFile = GetAbsolutePath(nameFile, folder, PREFIX_RIGHT_DATA, "");
	std::string nameRightIdFile = GetAbsolutePath(nameFile, folder, PREFIX_RIGHT_DATA, "Id");

	CompareFiles(nameOutputFile, nameRightFile);
	CompareFiles(nameOutputIdsFile, nameRightIdFile);


};
