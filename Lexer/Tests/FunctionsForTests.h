#pragma once

#include "../Parser.h"
#include "../Lexer.h"
#include "../StringPool.h"
#include "../Interpreter.h"
#include "../Token.h"
#include "../Grammar.h"

#include <iostream>
#include <time.h>

#include <iostream>
#include <fstream>
#include <string>

const std::string PATH_RIGHT_DATA = "Right\\";

struct TestNameFiles_
{
	const std::string nameFormatFiles = ".txt";
	const std::string nameCodeFile = "testProgram";
	const std::string nameErrorFile = "errorProgram";
	const std::string nameOutputFile = "outputProgram";
};

void CompareFiles(const std::string & first, const std::string & second);

void TestLexer(const std::string nameInputFile
				, const std::string nameErrorFile
				, const std::string nameOutputFile);
