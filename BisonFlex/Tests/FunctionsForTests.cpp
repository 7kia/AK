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
	std::ifstream	inputFile;
	std::ofstream	outFile;
	std::ofstream	idsFile;

	inputFile.open(inputFileName);
	outFile.open(outputFileName);
	idsFile.open(outputIdFileName);

	std::srand(static_cast<unsigned>(time(nullptr)));
	example::CCompilerDriver driver(outFile, outFile, idsFile);

	if (!driver.Compile(inputFile, outputFileName + ".obj"))
	{
		throw std::runtime_error("Was compiler errors");
	}
}

std::string	GetAbsolutePath(const std::string & name
							, const std::string & categoryFolder
							, const std::string & postfix
							, const std::string & additional)

{
	std::string result;

	if (!categoryFolder.empty())
	{
		result = postfix + categoryFolder + "/";
	}
	result += postfix + additional + name + TestNameFiles::nameFormatFiles;

	return result;
}


void TestLexer(const std::string & nameFile
			, const std::string & folder
			)
{
	
	std::string nameInputFile = GetAbsolutePath(nameFile, folder, "", "");
	std::string nameOutputFile = GetAbsolutePath(nameFile, folder, TestNameFiles::nameOutputFile, "");
	std::string nameOutputIdsFile = GetAbsolutePath(nameFile, folder, TestNameFiles::nameOutputFile, "Id");

	std::cout << nameFile << std::endl;
	BOOST_REQUIRE_NO_THROW(RunLexer(nameInputFile
									, nameOutputFile
									, nameOutputIdsFile
									));

	std::string nameRightFile = GetAbsolutePath(nameFile, folder, PREFIX_RIGHT_DATA, "");
	std::string nameRightIdFile = GetAbsolutePath(nameFile, folder, PREFIX_RIGHT_DATA, "Id");

	CompareFiles(nameOutputFile, nameRightFile);
	CompareFiles(nameOutputIdsFile, nameRightIdFile);


};
