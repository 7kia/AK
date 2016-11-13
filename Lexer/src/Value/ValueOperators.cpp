#include "stdafx.h"

#include "Value.h"


template<class TType>
bool CValue::AreBothValues(const CValue &left, const CValue &right)
{
	return (left.m_value.type() == typeid(TType))
		&& (right.m_value.type() == typeid(TType));
}

CValue::operator bool() const
{
	return ConvertToBool();
}

CValue CValue::operator +() const
{
	if (m_value.type() == typeid(double))
	{
		return *this;
	}
	if (m_value.type() == typeid(int))
	{
		return *this;
	}
	return GenerateError(*this, "+");
}

CValue CValue::operator -() const
{
	if (m_value.type() == typeid(double))
	{
		return Value(-AsDouble());
	}
	if (m_value.type() == typeid(int))
	{
		return Value(-AsInt());
	}
	return GenerateError(*this, "-");
}

CValue CValue::operator !() const
{
	if (m_value.type() == typeid(bool))
	{
		return Value(!AsBool());
	}
	return GenerateError(*this, "!");
}

CValue CValue::operator <(const CValue &other) const
{
	const auto &leftType = m_value.type();
	const auto &rightType = other.m_value.type();

	bool leftIsInt = (leftType == typeid(int));
	bool leftIsDouble = (leftType == typeid(double));
	bool rightIsInt = (rightType == typeid(int));
	bool rightIsDouble = (rightType == typeid(double));

	if (leftIsInt && rightIsInt)
	{
		return Value(AsInt() < other.AsInt());
	}
	if (((leftIsInt || rightIsInt) && (leftIsDouble || rightIsDouble))
		|| (leftIsDouble && rightIsDouble))
	{
		return Value(AsDouble() < other.AsDouble());
	}

	if (AreBothValues<std::string>(*this, other))
	{
		return Value(AsString() < other.AsString());
	}
	return GenerateError(*this, other, "<");
}

CValue CValue::operator ==(const CValue &other) const
{
	const auto &leftType = m_value.type();
	const auto &rightType = other.m_value.type();

	bool leftIsInt = (leftType == typeid(int));
	bool leftIsDouble = (leftType == typeid(double));
	bool rightIsInt = (rightType == typeid(int));
	bool rightIsDouble = (rightType == typeid(double));

	if (leftIsInt && rightIsInt)
	{
		return Value(AsInt() == other.AsInt());
	}
	if (((leftIsInt || rightIsInt) && (leftIsDouble || rightIsDouble))
		|| (leftIsDouble && rightIsDouble))
	{
		Value(FuzzyEquals(AsDouble(), other.AsDouble()));
	}

	if (AreBothValues<std::string>(*this, other))
	{
		return Value(AsString() == other.AsString());
	}
	if (AreBothValues<bool>(*this, other))
	{
		return Value(AsBool() == other.AsBool());
	}
	return GenerateError(*this, other, "==");
}

CValue CValue::operator &&(const CValue &other) const
{
	if (AreBothValues<bool>(*this, other))
	{
		return Value(AsBool() && other.AsBool());
	}
	return GenerateError(*this, other, "&&");
}

CValue CValue::operator ||(const CValue &other) const
{
	if (AreBothValues<bool>(*this, other))
	{
		return Value(AsBool() || other.AsBool());
	}
	return GenerateError(*this, other, "||");
}

CValue CValue::operator +(const CValue &other) const
{
	const auto &leftType = m_value.type();
	const auto &rightType = other.m_value.type();

	bool leftIsInt = (leftType == typeid(int));
	bool leftIsDouble = (leftType == typeid(double));
	bool rightIsInt = (rightType == typeid(int));
	bool rightIsDouble = (rightType == typeid(double));

	if (leftIsInt && rightIsInt)
	{
		return Value(AsInt() + other.AsInt());
	}
	if ( ((leftIsInt || rightIsInt) && (leftIsDouble || rightIsDouble))
			|| (leftIsDouble && rightIsDouble) )
	{
		return Value(AsDouble() + other.AsDouble());
	}

	/*
	if (leftType == typeid(double))
	{
		if (rightType == typeid(double))
		{
			return Value(AsDouble() + other.AsDouble());
		}
		// TODO : спроси у Шамбира почему есть этот if
		
		if (rightType == typeid(std::string))
		{
			return Value(::ToPrettyString(AsDouble()) + other.AsString());
		}
		
		
	}
	*/


	if (leftType == typeid(std::string))
	{
		// TODO : спроси у Шамбира почему есть этот if
		/*
		if (rightType == typeid(double))
		{
			return Value(AsString() + ::ToPrettyString(other.AsDouble()));
		}
		*/
		if (rightType == typeid(std::string))
		{
			return Value(AsString() + other.AsString());
		}
	}
	return GenerateError(*this, other, "+");
}

CValue CValue::operator -(const CValue &other) const
{
	// TODO : see can avoid dublicate code operator + /\ //
	const auto &leftType = m_value.type();
	const auto &rightType = other.m_value.type();

	bool leftIsInt = (leftType == typeid(int));
	bool leftIsDouble = (leftType == typeid(double));
	bool rightIsInt = (rightType == typeid(int));
	bool rightIsDouble = (rightType == typeid(double));

	if (leftIsInt && rightIsInt)
	{
		return Value(AsInt() - other.AsInt());
	}
	if (((leftIsInt || rightIsInt) && (leftIsDouble || rightIsDouble))
		|| (leftIsDouble && rightIsDouble))
	{
		return Value(AsDouble() - other.AsDouble());
	}
	
	return GenerateError(*this, other, "-");
}

CValue CValue::operator *(const CValue &other) const
{
	const auto &leftType = m_value.type();
	const auto &rightType = other.m_value.type();

	bool leftIsInt = (leftType == typeid(int));
	bool leftIsDouble = (leftType == typeid(double));
	bool rightIsInt = (rightType == typeid(int));
	bool rightIsDouble = (rightType == typeid(double));

	if (leftIsInt && rightIsInt)
	{
		return Value(AsInt() * other.AsInt());
	}
	if (((leftIsInt || rightIsInt) && (leftIsDouble || rightIsDouble))
		|| (leftIsDouble && rightIsDouble))
	{
		return Value(AsDouble() * other.AsDouble());
	}

	return GenerateError(*this, other, "*");
}

CValue CValue::operator /(const CValue &other) const
{
	const auto &leftType = m_value.type();
	const auto &rightType = other.m_value.type();

	bool leftIsInt = (leftType == typeid(int));
	bool leftIsDouble = (leftType == typeid(double));
	bool rightIsInt = (rightType == typeid(int));
	bool rightIsDouble = (rightType == typeid(double));

	if (leftIsInt && rightIsInt)
	{
		return Value(AsInt() / other.AsInt());
	}
	if (((leftIsInt || rightIsInt) && (leftIsDouble || rightIsDouble))
		|| (leftIsDouble && rightIsDouble))
	{
		return Value(AsDouble() / other.AsDouble());
	}

	return GenerateError(*this, other, "/");
}

CValue CValue::operator %(const CValue &other) const
{
	const auto &leftType = m_value.type();
	const auto &rightType = other.m_value.type();

	bool leftIsInt = (leftType == typeid(int));
	bool leftIsDouble = (leftType == typeid(double));
	bool rightIsInt = (rightType == typeid(int));
	bool rightIsDouble = (rightType == typeid(double));

	if (leftIsInt && rightIsInt)
	{
		return Value(AsInt() - other.AsInt());
	}
	if (((leftIsInt || rightIsInt) && (leftIsDouble || rightIsDouble))
		|| (leftIsDouble && rightIsDouble))
	{
		return Value(fmod(AsDouble(), other.AsDouble()));
	}

	return GenerateError(*this, other, "%");
}
