#pragma once

#include <unordered_map>
#include <memory>
#include <boost/optional.hpp>
#include "../Value/Value.h"
// TODO : see need old comments
/** Calculator context used to save the parsed expressions. This context is
* passed along to the example::Driver class and fill during parsing via bison
* actions. */

/**

		AST - Abstract syntax tree
		Класс хранящий области видимости, переменные, функции.
		На его основе будет сгенерированн объекстный код

*/

class CStringPool;
class CVariablesScope;
class IFunctionAST;

class CAST
{
public:
	CAST(std::ostream &output
		, std::ostream &errors
		, CStringPool &pool);
	~CAST();
//////////////////////////////////////////////////////////////////////
// Methods
	// TODO : restyle
public:
	void DefineVariable(unsigned nameId, const CValue &value);
	void AssignVariable(unsigned nameId, const CValue &value);
	CValue GetVariableValue(unsigned nameId)const;

	void PushScope(std::unique_ptr<CVariablesScope> && scope);
	std::unique_ptr<CVariablesScope> PopScope();
	size_t GetScopesCount()const;

	IFunctionAST *GetFunction(unsigned nameId)const;
	void AddFunction(unsigned nameId, IFunctionAST *function);

	std::string GetStringLiteral(unsigned stringId)const;

	void SetReturnValue(const boost::optional<CValue> &valueOpt);
	boost::optional<CValue> GetReturnValue()const;

	void PrintResult(const CValue &value);
	void PrintError(std::string const& message);

private:
	CVariablesScope *FindScopeWithVariable(unsigned nameId)const;
	bool ValidateValue(const CValue &value);
	void AddBuiltin(const std::string &name, std::unique_ptr<IFunctionAST> && function);
//////////////////////////////////////////////////////////////////////
// Data
private:
	boost::optional<CValue> m_returnValueOpt;

	std::unordered_map<unsigned, IFunctionAST*> m_functions;

	std::vector<std::unique_ptr<IFunctionAST>> m_builtins;
	std::vector<std::unique_ptr<CVariablesScope>> m_scopes;

	CStringPool &m_pool;// TOOD : see ncan rewrite with & insteat *
	std::ostream &m_output;
	std::ostream &m_errors;
};
