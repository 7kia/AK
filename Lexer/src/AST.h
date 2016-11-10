#pragma once

#include "expression.h"

#include <unordered_map>
// TODO : see need old comments
/** Calculator context used to save the parsed expressions. This context is
* passed along to the example::Driver class and fill during parsing via bison
* actions. */

/**

		AST - Abstract syntax tree
		Класс хранящий области видимости, переменные, функции.
		На его основе будет сгенерированн объекстный код

*/
class CAST
{
public:
	CInterpreterContext(CStringPool const& pool);

//////////////////////////////////////////////////////////////////////
// Methods
public:
	void	AssignVariable(unsigned stringId, double value);
	CValue	GetVariableValue(unsigned stringId);
	void	PrintResult(double value);

	CValue	GetVariableValue(unsigned stringId);
//////////////////////////////////////////////////////////////////////
// Data
private:	/// type of the variable storage
	typedef std::unordered_map<unsigned, CValue> variableMap;

	/// variable storage. maps variable string to doubles
	variableMap	variables;
	CStringPool const& m_pool;

	/// array of unassigned expressions found by the parser. these are then
	/// outputted to the user.
	std::vector<CNode*>	expressions;// TODO :: see need it, might need delete

};