#pragma once
#include <iostream>
#include <memory>

#include "Token.h"

class CInterpreter
{
public:
    CInterpreter(std::ostream &output);
    ~CInterpreter();

    void					EnterLoop(std::istream &input);

	void					ProcessLine(const std::string & line);

private:
	std::ostream &			m_output;
	SToken					m_token;// TODO : transfer, now neccessary for support multi-string comments

};
