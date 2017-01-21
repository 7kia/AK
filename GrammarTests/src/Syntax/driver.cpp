// $Id: driver.cc 39 2008-08-03 10:07:15Z tb $
/** \file driver.cc Implementation of the example::HybridWalkår class. */

#include "stdafx.h"

#include "driver.h"

static const char C_MAIN_FUNC[] = "main";

namespace example {



	HybridWalkår::HybridWalkår(std::istream &input
								, std::ostream &output
								, std::ostream &errors
								, std::ostream &ids)
		: trace_scanning(false)
		, trace_parsing(false)
		, m_outFile(output)
		, m_idsFile(ids)
		, m_errors(errors)
		, lexer(&std::cin, &output, &ids)
		, m_inputStream(input)
			//, m_parser(m_context) // TODO : see not forgot parser/lexer
	{

	};


	bool HybridWalkår::parse_stream(std::istream& in, const std::string& sname)
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

bool HybridWalkår::parse_file(const std::string &filename)
{
    std::ifstream in(filename.c_str());
    if (!in.good()) return false;
    return parse_stream(in, filename);
}

bool HybridWalkår::parse_string(const std::string &input, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname);
}

void HybridWalkår::error(const class location& l,
		   const std::string& m)
{
	//<< l << ": "
	*lexer.yyout  << m << std::endl;// TODO : yyout can be error(see Flex class
    std::cerr << m << std::endl;
}

void HybridWalkår::error(const std::string& m)
{
	*lexer.yyout << m << std::endl;
    std::cerr << m << std::endl;
}


bool HybridWalkår::Analyze(std::istream &input, const std::string &outputPath)
{
	try
	{
		parse_stream(input);
	}
	catch (std::exception const& ex)
	{
		OnFatalError(ex);
		return false;
	}
	return true;
}



void HybridWalkår::OnFatalError(std::exception const& ex)
{
	m_errors << "Fatal error: " << ex.what() << std::endl;
}

bool HybridWalkår::CheckInputSequence(const Tokens & tokens)
{
	return Analyze(m_inputStream, m_outputFileName);
}



} // namespace example
