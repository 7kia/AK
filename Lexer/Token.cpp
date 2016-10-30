#include "stdafx.h"
#include "Token.h"


SToken::SToken()
{
}

SToken::~SToken()
{
}

SToken::SToken(const SToken & token)
{
	position = token.position;
	id = token.id;

	switch (id)
	{

	case TokenType::INT:
		assert(false);
		break;
	case TokenType::FLOAT:
		doubleValue = token.doubleValue;
		break;

	case TokenType::CHAR:
		assert(false);
		break;
	case TokenType::STRING:
		assert(false);
		break;
	

	default:
		assert(false);
		break;
	}
}

SToken& SToken::operator=(const SToken & token)
{
	position = token.position;
	id = token.id;

	switch (id)
	{

	case TokenType::INT:
		assert(false);
		break;
	case TokenType::FLOAT:
		doubleValue = token.doubleValue;
		break;

	case TokenType::CHAR:
		assert(false);
		break;
	case TokenType::STRING:
		assert(false);
		break;


	default:
		assert(false);
		break;
	}

	return *this;
}
