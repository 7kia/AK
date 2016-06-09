#pragma once

#include "../Lexer.h"
#include "../Interpreter.h"

#include <iostream>
#include <time.h>

#include <iostream>
#include <fstream>
#include <string>

const std::string PATH_RIGHT_DATA = "Right\\";

namespace TestNameFiles
{
	static const std::string nameFormatFiles = ".txt";
	static const std::string nameCodeFile = "test";
	static const std::string nameErrorFile = "error";
	static const std::string nameOutputFile = "output";
}

void CompareFiles(const std::string & first, const std::string & second);

void RunLexer(const std::string nameInputFile, const std::string nameOutputFile);

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Run and test lexer for files have next names:
//
// input code file = TestNameFiles::nameCodeFile + suffixNametest + TestNameFiles_::nameFormatFiles
// error file = TestNameFiles::nameErrorFile + suffixNametest + TestNameFiles_::nameFormatFiles
// output code file = TestNameFiles::nameOutputFile + suffixNametest + TestNameFiles_::nameFormatFiles
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void TestLexer(const std::string & suffixNametest);
