// $Id: driver.cc 39 2008-08-03 10:07:15Z tb $
/** \file driver.cc Implementation of the example::Driver class. */

#include "stdafx.h"

#include <fstream>
#include <sstream>


#include "driver.h"
#include "AST/AST.h"
#include "scanner.h"

namespace example {

Driver::Driver()
    : trace_scanning(false)
	, trace_parsing(false)
	, m_ast(m_globalAst)
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
