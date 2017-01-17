#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "HybridWalkerExceptions.h"
#include "HybridWalker.h"
#include "Syntax\driver.h"
#include "Lexer/Interpreter.h"

static const int AMOUNT_ARGUMENTS = 3;
static const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";

void CheckParametrs(int argc);
using namespace example;

