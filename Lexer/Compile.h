#pragma once
#include <iostream>
#include <memory>

#include "Converter.h"

class CCompile
{
public:
    CCompile(std::ostream &output);
    ~CCompile();
//////////////////////////////////////////////////////////////////////
// Methods
public:
	void					Add(SToken token);

	void					OnError(SToken const& token);
	void					OnStackOverflow();
//////////////////////////////////////////////////////////////////////
// Data
private:
	std::ostream &			m_output;

	CConverter				m_conveter;
	SToken					m_token;// TODO : transfer, now neccessary for support multi-string comments

	bool					m_isErrorState = false;

};
