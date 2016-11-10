#include "stdafx.h"
#include "ASTNodes.h"


CBinaryExpressionAST::CBinaryExpressionAST(IExpressionASTUniquePtr &&left, BinaryOperation op, IExpressionASTUniquePtr &&right)
    : m_left(std::move(left))
    , m_operation(op)
    , m_right(std::move(right))
{
}

CValue CBinaryExpressionAST::Evaluate(CAST &context) const
{
    const CValue a = m_left->Evaluate(context);
    const CValue b = m_right->Evaluate(context);
    switch (m_operation)
    {
    case BinaryOperation::Less:
        return a < b;
    case BinaryOperation::Equals:
        return a == b;
    case BinaryOperation::Add:
        return a + b;
    case BinaryOperation::Substract:
        return a - b;
    case BinaryOperation::Multiply:
        return a * b;
    case BinaryOperation::Divide:
        return a / b;
    case BinaryOperation::Modulo:
        return a % b;
    }
    return CValue::FromErrorMessage("binary operation not implemented");
}


CUnaryExpressionAST::CUnaryExpressionAST(UnaryOperation op, IExpressionASTUniquePtr &&value)
	: m_operation(op)
	, m_expr(std::move(value))
{
}

CValue CUnaryExpressionAST::Evaluate(CAST &context) const
{
	const CValue value = m_expr->Evaluate(context);
	switch (m_operation)
	{
	case UnaryOperation::Plus:
		return +value;
	case UnaryOperation::Minus:
		return -value;
	}
	return CValue::FromErrorMessage("unary operation not implemented");
}


CLiteralAST::CLiteralAST(CValue value)
	: m_value(value)
{
}

CValue CLiteralAST::Evaluate(CAST &context) const
{
	(void)context;
	return m_value;
}


CVariableRefAST::CVariableRefAST(unsigned nameId)
	: m_nameId(nameId)
{
}

CValue CVariableRefAST::Evaluate(CAST &context) const
{
	return context.GetVariableValue(m_nameId);
}


CPrintAST::CPrintAST(IExpressionASTUniquePtr &&expr)
	: m_expr(std::move(expr))
{
}

void CPrintAST::Execute(CAST &context)const
{
	const CValue result = m_expr->Evaluate(context);
	context.PrintResult(result);
}


CAssignAST::CAssignAST(unsigned nameId, IExpressionASTUniquePtr &&value)
	: m_nameId(nameId)
	, m_value(std::move(value))
{
}

void CAssignAST::Execute(CAST &context)const
{
	const CValue value = m_value->Evaluate(context);
	context.AssignVariable(m_nameId, value);
}