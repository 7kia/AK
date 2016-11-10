// $Id: driver.cc 39 2008-08-03 10:07:15Z tb $
/** \file driver.cc Implementation of the example::Driver class. */

#include "stdafx.h"

#include <fstream>
#include <sstream>


#include "driver.h"
#include "AST.h"
#include "scanner.h"

namespace example {

Driver::Driver(class CAST& _calc)
    : trace_scanning(false),
      trace_parsing(false),
      calc(_calc)
{

}

bool Driver::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;

	m_outFile.open(m_outFileName);
	m_idsFile.open(m_fileIds);
	
    Scanner scanner(&in, &m_outFile, &m_idsFile);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    Parser parser(*this);
    parser.set_debug_level(trace_parsing);

	// \/\/					\/\/
	// TODO : rewrite the code block
	calc.clearExpressions();
	bool result = (parser.parse() == 0);
	if (result)
	{
		m_outFile << "Expressions:" << std::endl;
		for (unsigned int ei = 0; ei < calc.expressions.size(); ++ei)
		{
			m_outFile << "[" << ei << "]:" << std::endl;
			m_outFile << "tree:" << std::endl;
			calc.expressions[ei]->print(m_outFile);
			m_outFile << "evaluated: "
				<< calc.expressions[ei]->evaluate()
				<< std::endl;
		}
	}

    return (parser.parse() == 0);
	// /\/\					/\/\ /
}

bool Driver::parse_file(const std::string &filename
						, const std::string &outFileName
						, const std::string &idsFileName)
{
	m_outFileName = outFileName;
	m_fileIds = idsFileName;
    std::ifstream in(filename.c_str());
    if (!in.good()) return false;
    return parse_stream(in, filename);
}

bool Driver::parse_string(const std::string &input, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname);
}

void Driver::error(const class location& l,
		   const std::string& m)
{
	*lexer->yyout << l << ": " << m << std::endl;// TODO : yyout can be error(see Flex class
    std::cerr << l << ": " << m << std::endl;
}

void Driver::error(const std::string& m)
{
	*lexer->yyout << m << std::endl;
    std::cerr << m << std::endl;
}

} // namespace example
