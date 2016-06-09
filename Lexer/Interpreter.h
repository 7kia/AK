#pragma once
#include <iostream>
#include <memory>

class CInterpreter
{
public:
    CInterpreter(std::ostream &output);
    ~CInterpreter();

    void					EnterLoop(std::istream &input);

	void					ProcessLine(const std::string & line);

private:
	std::ostream &			m_output;
};
