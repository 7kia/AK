// Lab2-1Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "FunctionsForTests.h"
#include "TestsLexer.h"

using namespace std;

struct OldLexer_
{
	
};

/* //Заготовка
		BOOST_AUTO_TEST_CASE(second)
		{			
			BOOST_CHECK(false);
		}
*/

BOOST_FIXTURE_TEST_SUITE(OldLexer, OldLexer_)
	BOOST_AUTO_TEST_SUITE(small_tests)
		BOOST_AUTO_TEST_CASE(RecognizeNumber)
		{
			TestLexer("RecognizeNumber");
		}
		BOOST_AUTO_TEST_CASE(Conditions)
		{
			TestLexer("Conditions");
		}
		BOOST_AUTO_TEST_CASE(Loops)
		{
			TestLexer("Loops");
		}
		BOOST_AUTO_TEST_CASE(Identifier)
		{
			TestLexer("Identifier");
		}
		BOOST_AUTO_TEST_CASE(NotRightIdentifier)// TODO : test neccessary rewrite
		{
			TestLexer("NotRightIdentifier");
		}
		BOOST_AUTO_TEST_CASE(Number)// TODO : test for not right
		{
			TestLexer("Number");
		}
		
		BOOST_AUTO_TEST_CASE(Types)// TODO : test neccessary rewrite
		{
			TestLexer("Types");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(one_symbols_operations)
		BOOST_AUTO_TEST_CASE(OneSymbolOperations)
		{
			TestLexer("OneSymbolOperations");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(prefixes_types)
		BOOST_AUTO_TEST_CASE(PrefixType)
		{
			TestLexer("PrefixType");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(system_functions)
		BOOST_AUTO_TEST_CASE(SystemFunctions)
		{
			TestLexer("SystemFunctions");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(big_tests)
		BOOST_AUTO_TEST_CASE(first)
		{
			TestLexer("1");
		}
		BOOST_AUTO_TEST_CASE(second)
		{
			TestLexer("2");
		}	
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()// OldLexer_

