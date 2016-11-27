#include "stdafx.h"

#include "Value.h"
#include <stdexcept>
#include <boost/format.hpp>
#include <cmath>

namespace
{


std::string ToPrettyString(double value)
{
    std::string result = std::to_string(value);
    // Преобразуем 2.00000 в 2.
    while (!result.empty() && result.back() == '0')
    {
        result.pop_back();
    }
    if (!result.empty() && result.back() == '.')
    {
        result.pop_back();
    }

    return result;
}


enum idTypeNames
{
	INT = 0
	, FLOAT
	, BOOLEAN
	, STRING
};
static const std::string typeNames[] = 
{
	"Integer"
	, "Float"
	, "Boolean"
	, "String"	
};

struct TypeNameVisitor : boost::static_visitor<std::string>
{	
	std::string operator ()(int const&) const {
		return typeNames[idTypeNames::INT];
	}
	std::string operator ()(double const&) const {
		return typeNames[idTypeNames::FLOAT];
	}
	std::string operator ()(bool const&) const {
		return typeNames[idTypeNames::BOOLEAN];
	}
	std::string operator ()(std::string const&) const {
		return typeNames[idTypeNames::STRING];
	}
	std::string operator ()(std::exception_ptr const& value) {
		m_exception = value; return "Error";
	}

    std::exception_ptr m_exception;
};

} // anonymous namespace.

void CValue::RethrowIfException() const
{
    if (m_value.type() == typeid(std::exception_ptr))
    {
        std::rethrow_exception(boost::get<std::exception_ptr>(m_value));
    }
}

bool CValue::AsBool() const
{
    return boost::get<bool>(m_value);
}

const std::string &CValue::AsString() const
{
    return boost::get<std::string>(m_value);
}

int CValue::AsInt() const
{
	TypeNameVisitor visitor;
	std::string valueType = m_value.apply_visitor(visitor);

	if (valueType == typeNames[idTypeNames::FLOAT])
	{
		return int(boost::get<double>(m_value));
	}
	return boost::get<int>(m_value);// TOOD : see need additional check
}

double CValue::AsDouble() const
{
	TypeNameVisitor visitor;
	std::string valueType = m_value.apply_visitor(visitor);

	if (valueType == typeNames[idTypeNames::INT])// TOOD : see need additional check
	{
		return double(boost::get<int>(m_value));
	}

    return boost::get<double>(m_value);
}


CValue CValue::GenerateError(const CValue &value, const char *description)
{
    TypeNameVisitor visitor;
    std::string valueType = value.m_value.apply_visitor(visitor);

    // Прокидываем информацию об ошибке дальше.
    if (visitor.m_exception)
    {
        return CValue::FromError(visitor.m_exception);
    }

    boost::format formatter("No such unary operation: %1%%2%");
    formatter % description % valueType;

    return CValue::FromErrorMessage(boost::str(formatter));
}

CValue CValue::GenerateError(const CValue &left, const CValue &right, const char *description)
{
    TypeNameVisitor visitor;
    std::string leftType = left.m_value.apply_visitor(visitor);
    std::string rightType = right.m_value.apply_visitor(visitor);

    // Прокидываем информацию об ошибке дальше.
    if (visitor.m_exception)
    {
        return CValue::FromError(visitor.m_exception);
    }

    boost::format formatter("No such binary operation: %1% %2% %3%");
    formatter % leftType % description % rightType;

    return CValue::FromErrorMessage(boost::str(formatter));
}

CValue::CValue(const CValue::Value &value)
    : m_value(value)
{
}