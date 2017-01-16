// $Id: driver.cc 39 2008-08-03 10:07:15Z tb $
/** \file driver.cc Implementation of the example::CCompilerDriver class. */

#include "stdafx.h"

#include "driver.h"

static const char C_MAIN_FUNC[] = "main";

namespace example {



	CCompilerDriver::CCompilerDriver(std::ostream &output
									, std::ostream &errors
									, std::ostream &ids)
		: trace_scanning(false)
		, trace_parsing(false)
		, m_outFile(output)
		, m_idsFile(ids)
		, m_errors(errors)
		, lexer(&std::cin, &output, &ids)
		//, m_parser(m_context) // TODO : see not forgot parser/lexer
	{

	};

bool CCompilerDriver::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;

	
    //Scanner scanner(m_stringPool, m_context, &in, &m_outFile, &m_idsFile);
	lexer.SetInputFile(in);

	// was scanner
	lexer.set_debug(trace_scanning);
    

    Parser parser(*this);
    parser.set_debug_level(trace_parsing);

	// \/\/					\/\/
	// TODO : rewrite the code block
	

    return (parser.parse() == 0);
	// /\/\					/\/\ /
}

bool CCompilerDriver::parse_file(const std::string &filename)
{
    std::ifstream in(filename.c_str());
    if (!in.good()) return false;
    return parse_stream(in, filename);
}

bool CCompilerDriver::parse_string(const std::string &input, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname);
}

void CCompilerDriver::error(const class location& l,
		   const std::string& m)
{
	*lexer.yyout << l << ": " << m << std::endl;// TODO : yyout can be error(see Flex class
    std::cerr << l << ": " << m << std::endl;
}

void CCompilerDriver::error(const std::string& m)
{
	*lexer.yyout << m << std::endl;
    std::cerr << m << std::endl;
}


bool CCompilerDriver::Compile(std::istream &input, const std::string &outputPath)
{
	return ParseAst(input);
}

bool CCompilerDriver::ParseAst(std::istream & input)
{
	try
	{
		parse_stream(input);

		//ThrowIfCompileErrors();
	}
	catch (std::exception const& ex)
	{
		OnFatalError(ex);
		return false;
	}
	return true;
}



void CCompilerDriver::OnFatalError(std::exception const& ex)
{
	m_errors << "Fatal error: " << ex.what() << std::endl;
}



} // namespace example
