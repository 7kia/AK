#pragma once

#include "Node.h"

/*
class CNChar : public CNode
{
public:
	/// construct a constant calculation node from a value
	explicit CNChar(char _value)
		: CNode(), value(_value)
	{
	}

//////////////////////////////////////////////////////////////////////
// Methods
public:

	virtual char evaluate() const
	{
		return value;
	}

	void print(std::ostream &os, unsigned int depth) const override
	{
		os << indent(depth) << std::string(value, 1) << std::endl;
	}
//////////////////////////////////////////////////////////////////////
// Data
private:
	/// the constant value returned
	char	value;
};

class CNString : public CNode
{
public:
	/// construct a constant calculation node from a value
	explicit CNString(const std::string & _value)
		: CNode(), value(_value)
	{
	}

//////////////////////////////////////////////////////////////////////
// Methods
public:

	std::string evaluate() const
	{
		return value;
	}

	void print(std::ostream &os, unsigned int depth) const override
	{
		os << indent(depth) << std::string(value, 1) << std::endl;
	}
//////////////////////////////////////////////////////////////////////
// Data
private:
	/// the constant value returned
	std::string	value;
};
*/