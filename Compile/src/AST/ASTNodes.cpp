#include "stdafx.h"

#include "ASTNodes.h"
#include "../Compiler/FrontendContext.h"
#include "../Compiler/CodegenVisitor.h"
#include <limits>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cassert>

// ���������� ��� ��������� LLVM.
struct LiteralTypeEvaluator : boost::static_visitor<ExpressionType>
{
	ExpressionType operator ()(int const&) const
	{
		return ExpressionType::Integer;
	}

	ExpressionType operator ()(float const&) const
	{
		return ExpressionType::Float;
	}

	ExpressionType operator ()(bool const&) const
	{
		return ExpressionType::Boolean;
	}

	ExpressionType operator ()(std::vector<int> const&) const
	{
		return ExpressionType::IntegerArray;
	}

	ExpressionType operator ()(std::vector<float> const&) const
	{
		return ExpressionType::FloatArray;
	}

	ExpressionType operator ()(std::vector<bool> const&) const
	{
		return ExpressionType::BooleanArray;
	}

	ExpressionType operator ()(std::string const&)
	{
		return ExpressionType::String;
	}
};

// ���������� ��� ��������� LLVM.
struct LiteralToDoubleConverter : boost::static_visitor<float>
{
	float operator ()(int const& value) const
	{
		return float(value);
	}

	float operator ()(float const& value) const
	{
		return value;
	}

	float operator ()(bool const& value) const
	{
		return float(value);
	}


	float operator ()(std::string const& value)
	{
		return stof(value, 0);
	}
};

CPrintAST::CPrintAST(IExpressionASTUniquePtr &&expr)
	: m_expr(std::move(expr))
{
}

IExpressionAST &CPrintAST::GetValue()
{
	return *m_expr;
}

void CPrintAST::Accept(IStatementVisitor &visitor)
{
	visitor.Visit(*this);
}

CAssignAST::CAssignAST(unsigned nameId, IExpressionASTUniquePtr &&value)
	: m_nameId(nameId)
	, m_value(std::move(value))
{
}

unsigned CAssignAST::GetNameId() const
{
	return m_nameId;
}

IExpressionAST &CAssignAST::GetValue()
{
	return *m_value;
}

void CAssignAST::Accept(IStatementVisitor &visitor)
{
	visitor.Visit(*this);
}

CBinaryExpressionAST::CBinaryExpressionAST(IExpressionASTUniquePtr &&left, BinaryOperation op, IExpressionASTUniquePtr &&right)
	: m_left(std::move(left))
	, m_operation(op)
	, m_right(std::move(right))
{
}

void CBinaryExpressionAST::Accept(IExpressionVisitor &visitor)
{
	visitor.Visit(*this);
}

BinaryOperation CBinaryExpressionAST::GetOperation() const
{
	return m_operation;
}

IExpressionAST &CBinaryExpressionAST::GetLeft()
{
	return *m_left;
}

IExpressionAST &CBinaryExpressionAST::GetRight()
{
	return *m_right;
}

CUnaryExpressionAST::CUnaryExpressionAST(UnaryOperation op, IExpressionASTUniquePtr &&value)
	: m_operation(op)
	, m_expr(std::move(value))
{
}

void CUnaryExpressionAST::Accept(IExpressionVisitor &visitor)
{
	visitor.Visit(*this);
}

UnaryOperation CUnaryExpressionAST::GetOperation() const
{
	return m_operation;
}

IExpressionAST &CUnaryExpressionAST::GetOperand()
{
	return *m_expr;
}

CLiteralAST::CLiteralAST(const Value &value)
	: m_value(value)
{
}

void CLiteralAST::Accept(IExpressionVisitor &visitor)
{
	visitor.Visit(*this);
}

ExpressionType CLiteralAST::GetType() const
{
	LiteralTypeEvaluator visitor;
	return m_value.apply_visitor(visitor);
}

const CLiteralAST::Value &CLiteralAST::GetValue() const
{
	return m_value;
}


CArrayAST::CArrayAST(ExpressionList &&arguments)
	: m_values(std::move(arguments))
{
}

void CArrayAST::Accept(IExpressionVisitor &visitor)
{
	visitor.Visit(*this);
}

ExpressionType CArrayAST::GetType() const
{
	switch (m_values[0]->GetType())
	{
	case ExpressionType::Boolean:
		return ExpressionType::BooleanArray;
		break;
	case ExpressionType::Integer:
		return ExpressionType::IntegerArray;
		break;
	case ExpressionType::Float:
		return ExpressionType::FloatArray;
		break;
	default:
		throw std::runtime_error("Incorrect type value list, now not be list");
		break;
	}
	//return m_values[0]->GetType();
}

const ExpressionList & CArrayAST::GetValues() const
{
	return m_values;// TODO : see need check
}


CParameterDeclAST::CParameterDeclAST(unsigned nameId, ExpressionType type)
	: m_nameId(nameId)
{
	SetType(type);
}

void CParameterDeclAST::Accept(IExpressionVisitor &visitor)
{
	visitor.Visit(*this);
}

const unsigned &CParameterDeclAST::GetName() const
{
	return m_nameId;
}

CVariableRefAST::CVariableRefAST(unsigned nameId)
	: m_nameId(nameId)
{
}

void CVariableRefAST::Accept(IExpressionVisitor &visitor)
{
	visitor.Visit(*this);
}

unsigned CVariableRefAST::GetNameId() const
{
	return m_nameId;
}

CIfAst::CIfAst(IExpressionASTUniquePtr &&condition, StatementsList &&thenBody, StatementsList &&elseBody)
	: m_condition(std::move(condition))
	, m_thenBody(std::move(thenBody))
	, m_elseBody(std::move(elseBody))
{
}

IExpressionAST &CIfAst::GetCondition() const
{
	return *m_condition;
}

const StatementsList &CIfAst::GetThenBody() const
{
	return m_thenBody;
}

const StatementsList &CIfAst::GetElseBody() const
{
	return m_elseBody;
}

void CIfAst::Accept(IStatementVisitor &visitor)
{
	visitor.Visit(*this);
}

CAbstractLoopAst::CAbstractLoopAst(IExpressionASTUniquePtr &&condition, StatementsList &&body)
	: m_condition(std::move(condition))
	, m_body(std::move(body))
{
}

IExpressionAST &CAbstractLoopAst::GetCondition() const
{
	return *m_condition;
}

const StatementsList &CAbstractLoopAst::GetBody() const
{
	return m_body;
}

CWhileAst::CWhileAst(IExpressionASTUniquePtr &&condition, StatementsList &&body)
	: CAbstractLoopAst(std::move(condition), std::move(body))
{
}

void CWhileAst::Accept(IStatementVisitor &visitor)
{
	visitor.Visit(*this);
}

CRepeatAst::CRepeatAst(IExpressionASTUniquePtr &&condition, StatementsList &&body)
	: CAbstractLoopAst(std::move(condition), std::move(body))
{
}

void CRepeatAst::Accept(IStatementVisitor &visitor)
{
	visitor.Visit(*this);
}

CCallAST::CCallAST(unsigned nameId, ExpressionList && arguments)
	: m_nameId(nameId)
	, m_arguments(std::move(arguments))
{
}

void CCallAST::Accept(IExpressionVisitor &visitor)
{
	visitor.Visit(*this);
}

unsigned CCallAST::GetFunctionNameId() const
{
	return m_nameId;
}

const ExpressionList &CCallAST::GetArguments() const
{
	return m_arguments;
}

CFunctionAST::CFunctionAST(unsigned nameId, ExpressionType returnType, ParameterDeclList &&parameters, StatementsList && body)
	: m_nameId(nameId)
	, m_parameters(std::move(parameters))
	, m_body(std::move(body))
	, m_returnType(returnType)
{
}

unsigned CFunctionAST::GetNameId() const
{
	return m_nameId;
}

const ParameterDeclList &CFunctionAST::GetParameters() const
{
	return m_parameters;
}

const StatementsList &CFunctionAST::GetBody() const
{
	return m_body;
}

ExpressionType CFunctionAST::GetReturnType() const
{
	return m_returnType;
}

CReturnAST::CReturnAST(IExpressionASTUniquePtr &&value)
	: m_value(std::move(value))
{
}

IExpressionAST &CReturnAST::GetValue()
{
	return *m_value;
}

void CReturnAST::Accept(IStatementVisitor &visitor)
{
	visitor.Visit(*this);
}

CProgramAst::CProgramAst()
{
}

CProgramAst::~CProgramAst()
{
}

void CProgramAst::AddFunction(IFunctionASTUniquePtr &&function)
{

	m_functions.emplace_back(std::move(function));
}

const FunctionList &CProgramAst::GetFunctions() const
{
	return m_functions;
}

ExpressionType CAbstractExpressionAST::GetType() const
{
	if (!m_type.is_initialized())
	{
		throw std::logic_error("attempt to get expression type before it was assigned");
	}
	return *m_type;
}

void CAbstractExpressionAST::SetType(ExpressionType type)
{
	m_type = type;
}