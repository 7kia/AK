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

	case yy::parser::token_type::INT:
		assert(false);
		break;
	case FLOAT:
		doubleValue = token.doubleValue;
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
}

SToken& SToken::operator=(const SToken & token)
{
	position = token.position;
	id = token.id;

	switch (id)
	{

	case INT:
		assert(false);
		break;
	case FLOAT:
		doubleValue = token.doubleValue;
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

	return *this;
}
