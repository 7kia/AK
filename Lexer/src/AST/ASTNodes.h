#pragma once

#include <memory>
#include "../Value/Value.h"
class CAST;

class IExpressionAST;
class IStatementAST;
class IFunctionAST;

using IExpressionASTUniquePtr = std::unique_ptr<IExpressionAST>;
using IStatementASTUniquePtr = std::unique_ptr<IStatementAST>;
using IFunctionASTUniquePtr = std::unique_ptr<IFunctionAST>;
//using ExpressionList = std::vector<IExpressionASTUniquePtr>;
//using StatementsList = std::vector<IStatementASTUniquePtr>;
//using FunctionList = std::vector<IFunctionASTUniquePtr>;

class IExpressionAST
{
public:
	virtual ~IExpressionAST() = default;
	virtual CValue Evaluate(CAST & context)const = 0;
};

class IStatementAST
{
public:
	virtual ~IStatementAST() = default;
	virtual void Execute(CAST & context)const = 0;
};

enum class BinaryOperation
{
	Less,
	Equals,
	Add,
	Substract,
	Multiply,
	Divide,
	Modulo
};


class CBinaryExpressionAST : public IExpressionAST
{
public:
	CBinaryExpressionAST(IExpressionASTUniquePtr && left, BinaryOperation op, IExpressionASTUniquePtr && right);
	CValue Evaluate(CAST & context)const override;

private:
	IExpressionASTUniquePtr	m_left;
	const BinaryOperation	m_operation;
	IExpressionASTUniquePtr	m_right;
};

enum class UnaryOperation
{
	Plus,
	Minus
};

class CUnaryExpressionAST : public IExpressionAST
{
public:
	CUnaryExpressionAST(UnaryOperation op, IExpressionASTUniquePtr && value);
	CValue Evaluate(CAST & context)const override;

private:
	const UnaryOperation	m_operation;
	IExpressionASTUniquePtr m_expr;
};

class CLiteralAST : public IExpressionAST
{
public:
	CLiteralAST(CValue value);
	CValue Evaluate(CAST & context)const override;

private:
	const CValue m_value;
};

class CVariableRefAST : public IExpressionAST
{
public:
	CVariableRefAST(unsigned nameId);
	CValue Evaluate(CAST & context)const override;

private:
	const unsigned m_nameId;
};

class CPrintAST : public IStatementAST
{
public:
	CPrintAST(IExpressionASTUniquePtr && expr);
	void Execute(CAST & context)const override;

private:
	IExpressionASTUniquePtr m_expr;
};

class CAssignAST : public IStatementAST
{
public:
	CAssignAST(unsigned nameId, IExpressionASTUniquePtr && value);
	void Execute(CAST &context)const override;

private:
	const unsigned				m_nameId;
	IExpressionASTUniquePtr		m_value;
};
