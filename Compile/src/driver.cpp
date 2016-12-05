// $Id: driver.cc 39 2008-08-03 10:07:15Z tb $
/** \file driver.cc Implementation of the example::CCompilerDriver class. */

#include "stdafx.h"

#include "driver.h"

using std::bind;
using namespace std::placeholders;
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
		, m_context(errors, m_stringPool)
		, m_codegenContext(m_context)
		, lexer(m_stringPool, m_context, &std::cin, &output, &ids)
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

bool CCompilerDriver::DetectMainFunction(const CProgramAst & ast)
{
	unsigned mainId = m_stringPool.Insert(C_MAIN_FUNC);
	const FunctionList &functions = ast.GetFunctions();

	bool noMain = std::none_of(functions.begin(), functions.end(), [&](const IFunctionASTUniquePtr &fn) {
		return (fn->GetNameId() == mainId);
	});
	if (noMain)
	{
		m_context.PrintError("`main` function was not defined");
		return false;
	}
	return true;
}

bool CCompilerDriver::Compile(std::istream &input, const std::string &outputPath)
{
	return ParseAst(input) && GenerateCodeFromAst() && CompileModule(outputPath);
}

bool CCompilerDriver::ParseAst(std::istream & input)
{
	try
	{
		parse_stream(input);

		ThrowIfCompileErrors();
	}
	catch (std::exception const& ex)
	{
		OnFatalError(ex);
		return false;
	}
	return true;
}

bool CCompilerDriver::GenerateCodeFromAst()
{
	try
	{
		std::unique_ptr<CProgramAst> pProgram = lexer.TakeProgram();
		if (!DetectMainFunction(*pProgram))
		{
			return false;
		}

		CTypecheckVisitor visitor(m_context);
		visitor.RunSemanticPass(*pProgram);

		CCodeGenerator codegen(m_codegenContext);
		unsigned mainId = m_stringPool.Insert(C_MAIN_FUNC);
		for (const auto &pAst : pProgram->GetFunctions())
		{
			if (pAst->GetNameId() == mainId)
			{
				codegen.AcceptMainFunction(*pAst);
			}
			else
			{
				codegen.AcceptFunction(*pAst);
			}
		}

		m_codegenContext.GetModule().dump();
		ThrowIfCompileErrors();

		return true;
	}
	catch (std::exception const& ex)
	{
		OnFatalError(ex);
		return false;
	}
}

void CCompilerDriver::ThrowIfCompileErrors()
{
	if (0 == m_context.GetErrorsCount())
	{
		return;
	}

	const unsigned errorCount = m_context.GetErrorsCount();
	const bool useEnglishPluralForm = (errorCount % 10 != 1);
	std::stringstream message;
	message << errorCount << " compiler " << (useEnglishPluralForm ? "errors" : "error");

	throw std::runtime_error(message.str());
}

void CCompilerDriver::OnFatalError(std::exception const& ex)
{
	m_errors << "Fatal error: " << ex.what() << std::endl;
}

bool CCompilerDriver::CompileModule(const std::string &outputPath)
{
	const bool isDebug = false;
	CCompilerBackend backend;
	try
	{
		backend.GenerateObjectFile(m_codegenContext.GetModule(), isDebug, outputPath);
		return true;
	}
	catch (const std::exception &ex)
	{
		OnFatalError(ex);
		return false;
	}
}

} // namespace example
