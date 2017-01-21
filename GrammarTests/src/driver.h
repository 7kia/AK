// $Id: driver.h 17 2007-08-19 18:51:39Z tb $ 	
/** \file driver.h Declaration of the example::HybridWalker class. */

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <time.h>


#include "scanner.h"
#include "Grammar.h"
#include <sstream>

// forward declaration

/** The example namespace is used to encapsulate the three parser classes
 * example::Parser, example::Scanner and example::HybridWalker */
namespace example {

/** The HybridWalker class brings together all components. It creates an instance of
 * the Parser and Scanner classes and connects them. Then the input stream is
 * fed into the scanner object and the parser gets it's token
 * sequence. Furthermore the driver object is available in the grammar rules as
 * a parameter. Therefore the driver class contains a reference to the
 * structure into which the parsed data is saved. */
class HybridWalker
{
public:
    /// construct a new parser driver context
    HybridWalker(std::ostream &output
			, std::ostream &errors
			, std::ostream &ids);

    /// enable debug output in the flex scanner
    bool trace_scanning;

    /// enable debug output in the bison parser
    bool trace_parsing;

    /// stream name (file or input stream) used for error messages.
    std::string streamname;

    /** Invoke the scanner and parser for a stream.
     * @param in	input stream
     * @param sname	stream name for error messages
     * @return		true if successfully parsed
     */
    bool parse_stream(std::istream& in,
		      const std::string& sname = "stream input");

    /** Invoke the scanner and parser on an input string.
     * @param input	input string
     * @param sname	stream name for error messages
     * @return		true if successfully parsed
     */
    bool parse_string(const std::string& input,
		      const std::string& sname = "string stream");

    /** Invoke the scanner and parser on a file. Use parse_stream with a
     * std::ifstream if detection of file reading errors is required.
     * @param filename	input file name
     * @return		true if successfully parsed
     */
    bool parse_file(const std::string &filename);

    // To demonstrate pure handling of parse errors, instead of
    // simply dumping them on the standard error output, we will pass
    // them to the driver using the following two member functions.

    /** Error handling with associated line number. This can be modified to
     * output the error e.g. to a dialog box. */
    void error(const class location& l, const std::string& m);

    /** General error handling. This can be modified to output the error
     * e.g. to a dialog box. */
    void error(const std::string& m);

	//////////////////////////////////////////////////////
	// From llvm-4 example
	bool HybridWalker::Analyze(std::istream &input);
	bool HybridWalker::ParseAst(std::istream & input);
	void HybridWalker::ThrowIfCompileErrors();
	void HybridWalker::OnFatalError(std::exception const& ex);


///////////////////////////////////////////////////////////////
// Data
public:
    class Scanner	lexer;

	/** Name file where will write recognize ids
	* expressions. */
	std::ostream	&m_outFile;
	std::ostream	&m_idsFile;
	std::ostream	&m_errors;


};

} // namespace example
