#include "stdafx.h"


#include "ASTNodes.h"
#include "AST.h"
#include "StringPool.h"
#include "VariablesScope.h"
#include <iostream>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm.hpp>
#include <cmath>

namespace
{

	template <class TFunction>
	CValue ExecuteSafely(TFunction && fn)
	{
		try
		{
			return fn();
		}
		catch (std::exception const&)
		{
			return CValue::FromError(std::current_exception());
		}
	}

	class CSinFunction : public IFunctionAST
	{
	public:
		CValue Call(CAST &context, const std::vector<CValue> &arguments) const override
		{
			(void)context;
			return ExecuteSafely([&] {
				double radians = arguments.at(0).AsDouble();
				return CValue::FromDouble(std::sin(radians));
			});
		}

		unsigned GetNameId() const override
		{
			return 0;
		}
	};

	class CRandFunction : public IFunctionAST
	{
	public:
		CValue Call(CAST &context, const std::vector<CValue> &arguments) const override
		{
			(void)context;
			return ExecuteSafely([&] {
				double minimum = arguments.at(0).AsDouble();
				double maximum = arguments.at(1).AsDouble();
				if (minimum > maximum)
				{
					return CValue::FromErrorMessage("invalid arguments for rand - range maximum is lesser than minimum.");
				}
				double rand0to1 = double(std::rand()) / std::numeric_limits<unsigned>::max();

				return CValue::FromDouble((maximum - minimum) * rand0to1 + minimum);
			});
		}

		unsigned GetNameId() const override
		{
			return 0;
		}
	};

}

CAST::CAST()
{
	AddBuiltin("sin", std::unique_ptr<IFunctionAST>(new CSinFunction));
	AddBuiltin("rand", std::unique_ptr<IFunctionAST>(new CRandFunction));
}

CAST::~CAST()
{
}

void CAST::SetOutputStream(std::ostream & output)
{
	m_output = &output;
}

void CAST::SetErrorStream(std::ostream & errors)
{
	m_errors = &errors;
}

void CAST::SetStringPool(CStringPool & pool)
{
	m_pool = &pool;
}

void CAST::DefineVariable(unsigned nameId, const CValue &value)
{
	if (ValidateValue(value))
	{
		m_scopes.back()->AssignVariable(nameId, value);
	}
}

void CAST::AssignVariable(unsigned nameId, const CValue &value)
{
	if (ValidateValue(value))
	{
		if (CVariablesScope *pScope = FindScopeWithVariable(nameId))
		{
			pScope->AssignVariable(nameId, value);
		}
		else
		{
			DefineVariable(nameId, value);
		}
	}
}

CValue CAST::GetVariableValue(unsigned nameId) const
{
	if (CVariablesScope *pScope = FindScopeWithVariable(nameId))
	{
		return *pScope->GetVariableValue(nameId);
	}
	return CValue::FromErrorMessage("unknown variable " + m_pool->GetString(nameId));
}

void CAST::PushScope(std::unique_ptr<CVariablesScope> &&scope)
{
	m_scopes.emplace_back(std::move(scope));
}

std::unique_ptr<CVariablesScope> CAST::PopScope()
{
	std::unique_ptr<CVariablesScope> ret(m_scopes.back().release());
	m_scopes.pop_back();
	return ret;
}

size_t CAST::GetScopesCount() const
{
	return m_scopes.size();
}

IFunctionAST *CAST::GetFunction(unsigned nameId) const
{
	try
	{
		return m_functions.at(nameId);
	}
	catch (std::exception const&)
	{
		return nullptr;
	}
}

void CAST::AddFunction(unsigned nameId, IFunctionAST *function)
{
	if (function)
	{
		m_functions[nameId] = function;
	}
}

std::string CAST::GetStringLiteral(unsigned stringId) const
{
	return m_pool->GetString(stringId);
}

void CAST::PrintResult(CValue const& value)
{
	try
	{
		*m_output << "  " << value.ToString() << std::endl;
	}
	catch (const std::exception &ex)
	{
		PrintError(ex.what());
	}
}

void CAST::PrintError(const std::string &message)
{
	*m_errors << "  Error: " << message << std::endl;
}

bool CAST::ValidateValue(const CValue &value)
{
	try
	{
		value.RethrowIfException();
		return true;
	}
	catch (std::exception const& ex)
	{
		PrintError(ex.what());
		return false;
	}
}

void CAST::SetReturnValue(boost::optional<CValue> const& valueOpt)
{
	m_returnValueOpt = valueOpt;
}

boost::optional<CValue> CAST::GetReturnValue() const
{
	return m_returnValueOpt;
}

CVariablesScope *CAST::FindScopeWithVariable(unsigned nameId) const
{
	auto range = boost::adaptors::reverse(m_scopes);
	auto it = boost::find_if(range, [=](const auto &pScope) {
		return pScope->HasVariable(nameId);
	});
	if (it != range.end())
	{
		return it->get();
	}
	return nullptr;
}

void CAST::AddBuiltin(const std::string &name, std::unique_ptr<IFunctionAST> &&function)
{
	m_builtins.emplace_back(std::move(function));
	unsigned nameRand = m_pool->Insert(name);
	m_functions[nameRand] = m_builtins.back().get();
}
