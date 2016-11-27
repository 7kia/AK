#include "stdafx.h"
#include "Value.h"

namespace
{

	// Конвертирует значение в Boolean (C++ bool).
	struct BooleanConverter : boost::static_visitor<bool>
	{
		bool operator ()(int const& value) const {
			return value;
		}
		bool operator ()(double const& value) const {
			return FuzzyEquals(value, 0);
		}
		bool operator ()(bool const& value) const {
			return value;
		}
		bool operator ()(std::string const& value) const {
			return !value.empty();
		}
		bool operator ()(std::exception_ptr const&) {
			return false;
		}
	};

	// Конвертирует значение в String (C++ std::string).
	struct StringConverter : boost::static_visitor<std::string>
	{
		std::string operator ()(int const& value) const {
			return std::to_string(value);// TODO : see is correct ToPrettyString
		}
		std::string operator ()(double const& value) const {
			return std::to_string(value);
		}
		std::string operator ()(bool const& value) const {
			return ToPrettyString(value);
		}
		std::string operator ()(std::string const& value) const {
			return value;
		}
		std::string operator ()(std::exception_ptr const& value) {
			std::rethrow_exception(value);
		}
	};

}

CValue CValue::FromError(const std::exception_ptr &value)
{
	return Value(value);
}

CValue CValue::FromErrorMessage(const std::string &message)
{
	return CValue::FromError(std::make_exception_ptr(std::runtime_error(message)));
}

CValue CValue::FromInt(int value)
{
	return CValue(value);
}

CValue CValue::FromDouble(double value)
{
	return Value(value);
}

CValue CValue::FromBoolean(bool value)
{
	return Value(value);
}

CValue CValue::FromString(const std::string &value)
{
	return Value(value);
}

std::string CValue::ToString() const
{
	return TryConvertToString();
}


std::string CValue::TryConvertToString() const
{
	StringConverter converter;
	std::string value = m_value.apply_visitor(converter);
	return value;
}

bool CValue::ConvertToBool() const
{
	BooleanConverter converter;
	return m_value.apply_visitor(converter);
}
