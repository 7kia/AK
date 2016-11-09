#pragma once
#include <boost/variant.hpp>
#include <iostream>

// \/ //
// TODO : see can it transfer to something namespace
std::string ToPrettyString(bool value)
{
	return value ? "true" : "false";
}

bool FuzzyEquals(double left, double right)
{
	return std::fabs(left - right) >= std::numeric_limits<double>::epsilon();
}
// /\ //

class CValue
{
public:
	using Value = boost::variant<
		std::exception_ptr,
		int,
		double,
		bool,
		std::string
	>;


    CValue() = default;

//////////////////////////////////////////////////////////////////////
// Methods
public:

	//--------------------------------------------
	// ConvertToValue.cpp
    static CValue FromError(const std::exception_ptr &value);
    static CValue FromErrorMessage(const std::string &message);
	static CValue FromInt(int value);
    static CValue FromDouble(double value);
    static CValue FromBoolean(bool value);
    static CValue FromString(const std::string &value);

    // Преобразует в строку. Перебрасывает исключение, если объект хранит ошибку.
    std::string ToString()const;
	//--------------------------------------------

	//--------------------------------------------
	// ValueOperators.cpp
    // Унарные и бинарные операции с проверкой типов.
    explicit operator bool()const;
    CValue operator +()const;
    CValue operator -()const;
    CValue operator !()const;
    CValue operator <(const CValue &other)const;// TODO : add > <= >=
    CValue operator ==(const CValue &other)const;
    CValue operator &&(const CValue &other)const;
    CValue operator ||(const CValue &other)const;
    CValue operator +(const CValue &other)const;
    CValue operator -(const CValue &other)const;
    CValue operator *(const CValue &other)const;
    CValue operator /(const CValue &other)const;
    CValue operator %(const CValue &other)const;
	//--------------------------------------------

    // Перебрасывает исключение, если объект хранит ошибку.
    void RethrowIfException()const;

    // Прямое приведение типов,
    // Выбрасывает boost::bad_get в случае несоответствия типа ожидаемому.
    bool AsBool()const;
    const std::string & AsString()const;
	int AsInt() const;
    double AsDouble()const;

//////////////////////////////////////////////////////////////////////
// Data
private:
    template<class TType>
    static bool AreBothValues(const CValue &left, const CValue &right);

    static CValue GenerateError(const CValue &value, const char *description);
    static CValue GenerateError(const CValue &left, const CValue &right, const char *description);

    CValue(Value const& value);

	//--------------------------------------------
	// ConvertToValue.cpp
    std::string		TryConvertToString() const;
    bool			ConvertToBool() const;
	//--------------------------------------------

    Value m_value;
};
