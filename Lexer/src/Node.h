#pragma once

#include <map>
#include <vector>
#include <ostream>
#include <stdexcept>
#include <cmath>


class CNode
{
public:
	virtual ~CNode() {};
//////////////////////////////////////////////////////////////////////
// Methods
public:
	/// output the calculation tree to the given stream. tries to format the
	/// output to make tree levels visible.
	virtual void	print(std::ostream &os, unsigned int depth = 0) const = 0;

	/// helper function for print() which makes the indention string
	static inline std::string indent(unsigned int d)
	{
		return std::string(d * 2, ' ');
	}
};


/** CalcNode is the abstract base class for calculation nodes. From it the
* different nullary, unary and binary nodes are derived. */
class CalcNode
	: public CNode
{
public:
	CalcNode()
		: CNode()
	{

	}
	/// required for virtual functions. in the derived classes the operands are
	/// deleted.
	virtual ~CalcNode()
	{
	}
//////////////////////////////////////////////////////////////////////
// Methods
public:
	/// evaluate the complete calculation tree and return the floating point
	/// result value
	virtual double	evaluate() const = 0;


};

