// $Id: driver.h 17 2007-08-19 18:51:39Z tb $ 	
/** \file driver.h Declaration of the example::Driver class. */

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "AST/StringPool.h"
#include "AST/ASTNodes.h"
#include "AST/AST.h"

// forward declaration

/** The example namespace is used to encapsulate the three parser classes
 * example::Parser, example::Scanner and example::Driver */
namespace example {

/** The Driver class brings together all components. It creates an instance of
 * the Parser and Scanner classes and connects them. Then the input stream is
 * fed into the scanner object and the parser gets it's token
 * sequence. Furthermore the driver object is available in the grammar rules as
 * a parameter. Therefore the driver class contains a reference to the
 * structure into which the parsed data is saved. */
class Driver
{
public:
    /// construct a new parser driver context
    Driver(std::ostream &output
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

///////////////////////////////////////////////////////////////
// Data
public:
    class Scanner*	lexer;

	CAST			m_globalAst;
    CProgramAst		m_ast;

	/** Name file where will write recognize ids
	* expressions. */
	std::ostream	&m_outFile;
	std::ostream	&m_idsFile;

private:
	CStringPool		m_stringPool;

};

} // namespace example
