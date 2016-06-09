#pragma once
#include <iostream>
#include <memory>

class CInterpreter
{
public:
    CInterpreter();
    ~CInterpreter();

    void					EnterLoop(std::istream &input);

	void					ProcessLine(const std::string & line);
};
