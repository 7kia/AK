// $Id: expression.h 48 2009-09-05 08:07:10Z tb $
/** \file expression.h Implements an example calculator class group. */

#pragma once

#include "Node.h"
#include "Value\Value.h"

/** Calculation node always returning a constant value. */
class CNConstant : public CalcNode
{
public:
	/// construct a constant calculation node from a value
	explicit CNConstant(double _value)
		: CalcNode(), value(_value)
	{
	}

//////////////////////////////////////////////////////////////////////
// Methods
public:

	virtual double evaluate() const
	{
		return value;
	}

	virtual void print(std::ostream &os, unsigned int depth) const
	{
		os << indent(depth) << value << std::endl;
	}
//////////////////////////////////////////////////////////////////////
// Data
private:
	/// the constant value returned
	double	value;
};

/** Calculation node negating the value of the operand subtree. */
class CNNegate : public CalcNode
{
public:
	explicit CNNegate(CalcNode* _node)
		: CalcNode(), node(_node)
	{
	}

	virtual ~CNNegate()
	{
		delete node;
	}
//////////////////////////////////////////////////////////////////////
// Methods
public:
	

	virtual double evaluate() const
	{
		return -node->evaluate();
	}

	virtual void print(std::ostream &os, unsigned int depth) const
	{
		os << indent(depth) << "- negate" << std::endl;
		node->print(os, depth + 1);
	}
//////////////////////////////////////////////////////////////////////
// Data
private:
	/// calculation subtree
	CalcNode* 	node;

};

/** Calculation node adding two operand nodes. */
class CNAdd : public CalcNode
{
public:
	explicit CNAdd(CalcNode* _left, CalcNode* _right)
		: CalcNode(), left(_left), right(_right)
	{
	}

	virtual ~CNAdd()
	{
		delete left;
		delete right;
	}
//////////////////////////////////////////////////////////////////////
// Methods
public:
	virtual double evaluate() const
	{
		return left->evaluate() + right->evaluate();
	}

	virtual void print(std::ostream &os, unsigned int depth) const
	{
		os << indent(depth) << "+ add" << std::endl;
		left->print(os, depth + 1);
		right->print(os, depth + 1);
	}
//////////////////////////////////////////////////////////////////////
// Data
private:
	/// left calculation operand
	CalcNode* 	left;

	/// right calculation operand
	CalcNode* 	right;
};

/** Calculation node subtracting two operand nodes. */
class CNSubtract : public CalcNode
{
public:
	explicit CNSubtract(CalcNode* _left, CalcNode* _right)
		: CalcNode(), left(_left), right(_right)
	{
	}

	virtual ~CNSubtract()
	{
		delete left;
		delete right;
	}
//////////////////////////////////////////////////////////////////////
// Methods
public:
	virtual double evaluate() const
	{
		return left->evaluate() - right->evaluate();
	}

	virtual void print(std::ostream &os, unsigned int depth) const
	{
		os << indent(depth) << "- subtract" << std::endl;
		left->print(os, depth + 1);
		right->print(os, depth + 1);
	}
//////////////////////////////////////////////////////////////////////
// Data
private:
	/// left calculation operand
	CalcNode* 	left;

	/// right calculation operand
	CalcNode* 	right;
};

/** Calculation node multiplying two operand nodes. */
class CNMultiply : public CalcNode
{
public:
	explicit CNMultiply(CalcNode* _left, CalcNode* _right)
		: CalcNode(), left(_left), right(_right)
	{
	}

	virtual ~CNMultiply()
	{
		delete left;
		delete right;
	}
//////////////////////////////////////////////////////////////////////
// Methods
public:
	virtual double evaluate() const
	{
		return left->evaluate() * right->evaluate();
	}

	virtual void print(std::ostream &os, unsigned int depth) const
	{
		os << indent(depth) << "* multiply" << std::endl;
		left->print(os, depth + 1);
		right->print(os, depth + 1);
	}
//////////////////////////////////////////////////////////////////////
// Data
private:
	/// left calculation operand
	CalcNode* 	left;

	/// right calculation operand
	CalcNode* 	right;
};

/** Calculation node dividing two operand nodes. */
class CNDivide : public CalcNode
{
public:
	explicit CNDivide(CalcNode* _left, CalcNode* _right)
		: CalcNode(), left(_left), right(_right)
	{
	}

	virtual ~CNDivide()
	{
		delete left;
		delete right;
	}
//////////////////////////////////////////////////////////////////////
// Methods
public:
	virtual double evaluate() const
	{
		return left->evaluate() / right->evaluate();
	}

	virtual void print(std::ostream &os, unsigned int depth) const
	{
		os << indent(depth) << "/ divide" << std::endl;
		left->print(os, depth + 1);
		right->print(os, depth + 1);
	}
//////////////////////////////////////////////////////////////////////
// Data
private:
	/// left calculation operand
	CalcNode* 	left;

	/// right calculation operand
	CalcNode* 	right;
};

/** Calculation node calculating the remainder of an integer division of two
 * operand nodes. */
class CNModulo : public CalcNode
{
public:
	explicit CNModulo(CalcNode* _left, CalcNode* _right)
		: CalcNode(), left(_left), right(_right)
	{
	}

	virtual ~CNModulo()
	{
		delete left;
		delete right;
	}
//////////////////////////////////////////////////////////////////////
// Methods
public:
	virtual double evaluate() const
	{
		return std::fmod(left->evaluate(), right->evaluate());
	}

	virtual void print(std::ostream &os, unsigned int depth) const
	{
		os << indent(depth) << "% modulo" << std::endl;
		left->print(os, depth + 1);
		right->print(os, depth + 1);
	}
//////////////////////////////////////////////////////////////////////
// Data
private:
	/// left calculation operand
	CalcNode* 	left;

	/// right calculation operand
	CalcNode* 	right;
};

/** Calculation node raising one operand to the power of the second. */
class CNPower : public CalcNode
{
public:
	explicit CNPower(CalcNode* _left, CalcNode* _right)
		: CalcNode(), left(_left), right(_right)
	{
	}

	virtual ~CNPower()
	{
		delete left;
		delete right;
	}
//////////////////////////////////////////////////////////////////////
// Methods
public:

	virtual double evaluate() const
	{
		return std::pow(left->evaluate(), right->evaluate());
	}

	virtual void print(std::ostream &os, unsigned int depth) const
	{
		os << indent(depth) << "^ power" << std::endl;
		left->print(os, depth + 1);
		right->print(os, depth + 1);
	}
//////////////////////////////////////////////////////////////////////
// Data
private:
	/// left calculation operand
	CalcNode* 	left;

	/// right calculation operand
	CalcNode* 	right;
};

// TODO : transfer to CharNodes.h , see why mot work "os <<"
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

class CNBool : public CNode
{
public:
	/// construct a constant calculation node from a value
	explicit CNBool(bool _value)
		: CNode(), value(_value)
	{
	}

//////////////////////////////////////////////////////////////////////
// Methods
public:

	bool evaluate() const
	{
		return value;
	}

	void print(std::ostream &os, unsigned int depth) const override
	{
		os << indent(depth) << value << std::endl;
	}
//////////////////////////////////////////////////////////////////////
// Data
private:
	/// the constant value returned
	bool	value;
};