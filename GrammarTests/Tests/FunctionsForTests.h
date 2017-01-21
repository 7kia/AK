#pragma once

#include "../src/driver.h"

#include <iostream>
#include <time.h>

#include <iostream>
#include <fstream>
#include <string>

const std::string PREFIX_RIGHT_DATA = "Right";

namespace TestNameFiles
{
	static const std::string nameFormatFiles = ".txt";
	static const std::string nameIdFile = "Id";// there will content id(see old lexer
	static const std::string nameErrorFile = "Error";
	static const std::string nameOutputFile = "Output";
}

void CompareFiles(const std::string & first, const std::string & second);

void RunLexer(const std::string &inputFileName
			, const std::string &outputFileName
			, const std::string &outputIdFileName
			);

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// TODO : rewrite 
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void			TestLexer(const std::string & nameFile
						, const std::string & folder);

// @param name - test name 
// @param categoryFolder - Category, for example, Syntax
// @param postfix - For example, "Output"
// @param additional - Usual "Id"
std::string		GetAbsolutePath(const std::string & name
								, const std::string & categoryFolder
								, const std::string & postfix
								, const std::string & additional);
