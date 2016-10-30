#include "stdafx.h"


#include "Compile.h"
#include "Lexer.h"
#include "Grammar.h"

CCompile::CCompile(std::ostream &output)
	: m_output(output)
{
}

CCompile::~CCompile()
{
}

void CCompile::Add(SToken token)
{
	// TODO : see can rewrite without dublicate
	switch (token.id)
	{

	case INT:
		assert(false);
		break;
	case FLOAT:
		m_output << " Float = " << token.doubleValue << std::endl;
		break;
	case CHAR:
		assert(false);
		break;
	case STRING:
		assert(false);
		break;


	default:
		assert(false);
		break;
	}
	
	m_token = token;
}


void CCompile::OnError(const SToken &token)
{
	std::cerr << "Syntax error at position " << token.position << std::endl;
	m_isErrorState = true;
}

void CCompile::OnStackOverflow()
{
	std::cerr << "LALR parser stack overflow occured." << std::endl;
	m_isErrorState = true;
}