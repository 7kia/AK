#include "stdafx.h"
#include "AST.h"

CValue CAST::GetVariableValue(unsigned stringId)
{
	try
	{
		return m_variables.at(stringId);
	}
	catch (std::exception const&)
	{
		std::cerr << "undefined variable " << m_pool.GetString(stringId) << std::endl;
		return 0;
	}
}