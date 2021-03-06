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
	BOOST_AUTO_TEST_SUITE(Syntax)

		

		BOOST_AUTO_TEST_CASE(Comments)
		{
			TestLexer("Comments", "Syntax");
		}

	/*
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
	*/
		
		BOOST_AUTO_TEST_SUITE(Types)

			BOOST_AUTO_TEST_CASE(Numbers)// TODO : test for not right
			{
				TestLexer("Numbers", "Syntax");
			}

			BOOST_AUTO_TEST_CASE(Boolean)
			{
				TestLexer("Boolean", "Syntax");
			}

			BOOST_AUTO_TEST_CASE(Chars)
			{
				TestLexer("Chars", "Syntax");
			}

			BOOST_AUTO_TEST_CASE(Strings)
			{
				TestLexer("Strings", "Syntax");
			}

			BOOST_AUTO_TEST_CASE(ModificationsTypes)
			{
				TestLexer("ModificationsTypes", "Syntax");
			}

			BOOST_AUTO_TEST_CASE(Arrays)
			{
				TestLexer("Arrays", "Syntax");
			}

			BOOST_AUTO_TEST_CASE(Pointers)
			{
				TestLexer("Pointers", "Syntax");
			}
		BOOST_AUTO_TEST_SUITE_END()
			//TwoSymbolOperations.txt
		BOOST_AUTO_TEST_SUITE(SystemFunctions)// TODO : rewrite
			BOOST_AUTO_TEST_CASE(All)
			{
				TestLexer("SystemFunctions", "Syntax");
			}
		BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_SUITE(Operations)// TODO : rewrite
			BOOST_AUTO_TEST_CASE(OneSymbolOperations)
			{
				TestLexer("OneSymbolOperations", "Syntax");
			}
			BOOST_AUTO_TEST_CASE(TwoSymbolOperations)
			{
				TestLexer("TwoSymbolOperations", "Syntax");
			}
			BOOST_AUTO_TEST_CASE(LogicOperations)
			{
				TestLexer("LogicOperations", "Syntax");
			}
			BOOST_AUTO_TEST_CASE(BitOperations)
			{
				TestLexer("BitOperations", "Syntax");
			}
		BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_SUITE(Keywords)
			BOOST_AUTO_TEST_CASE(Conditions)
			{
				TestLexer("Conditions", "Syntax");
			}

			BOOST_AUTO_TEST_CASE(Loops)
			{
				TestLexer("Loops", "Syntax");
			}
		BOOST_AUTO_TEST_SUITE_END()
/*
BOOST_AUTO_TEST_CASE(Types)// TODO : test neccessary rewrite
		{
			TestLexer("Types");
		}
*/
		
	BOOST_AUTO_TEST_SUITE_END()
		/*
	BOOST_AUTO_TEST_SUITE(one_symbols_operations)
		BOOST_AUTO_TEST_CASE(OneSymbolOperations)
		{
			TestLexer("OneSymbolOperations", "Syntax");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(prefixes_types)
		BOOST_AUTO_TEST_CASE(PrefixType)
		{
			TestLexer("PrefixType", "Syntax");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(system_functions)
		BOOST_AUTO_TEST_CASE(SystemFunctions)
		{
			TestLexer("SystemFunctions", "Syntax");
		}
	BOOST_AUTO_TEST_SUITE_END()
	*/

	
	BOOST_AUTO_TEST_SUITE(Programs)
		BOOST_AUTO_TEST_CASE(HelloWorld)
		{
			TestLexer("HelloWorld", "Programs");
		}
		BOOST_AUTO_TEST_CASE(BubbleSort)
		{
			TestLexer("BubbleSort", "Programs");
		}
		BOOST_AUTO_TEST_CASE(MatrixMultiplication)
		{
			TestLexer("MatrixMultiplication", "Programs");
		}
	BOOST_AUTO_TEST_SUITE_END()
		

BOOST_AUTO_TEST_SUITE_END()// OldLexer_

