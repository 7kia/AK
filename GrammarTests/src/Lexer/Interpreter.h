#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Lexer.h"

class CInterpreter
{
public:
    CInterpreter(std::ostream &output);
    ~CInterpreter();

    void					EnterLoop(std::istream &input);

	void					ProcessLine(const std::string & line);

public:
	std::vector<SToken>		m_tokens;
private:
	std::ostream &			m_output;
	SToken					m_token;// TODO : transfer, now neccessary for support multi-string comments

};
