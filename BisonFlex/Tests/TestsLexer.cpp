// Lab2-1Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "TestsLexer.h"

using namespace std;

struct Lexer_
{

};

/* //Заготовка
		BOOST_AUTO_TEST_CASE(second)
		{			
			BOOST_CHECK(false);
		}
*/

BOOST_FIXTURE_TEST_SUITE(Lexer, Lexer_)
	//////////////////////////////////////////////////////////
	//
	//		Syntax
	//
	//////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(Syntax)
		BOOST_AUTO_TEST_CASE(Arrays)
		{
			TestLexer("Arrays", "Syntax");
			//BOOST_CHECK(false);
		}

		BOOST_AUTO_TEST_CASE(Chars)
		{
			//BOOST_CHECK(false);
			TestLexer("Chars", "Syntax");
		}

		BOOST_AUTO_TEST_CASE(Int_and_double)
		{
			TestLexer("Int_and_double", "Syntax");
		}

		BOOST_AUTO_TEST_CASE(Conditions)
		{
			TestLexer("Conditions", "Syntax");
		}
		//////////////////////////
		//		Operations
		//////////////////////////
		BOOST_AUTO_TEST_SUITE(Operations)// TODO : rewrite
			BOOST_AUTO_TEST_CASE(ArithmeticOperations)
			{
				TestLexer("OneSymbolOperations", "Syntax");
			}
			BOOST_AUTO_TEST_CASE(StringOperations)
			{
				//BOOST_CHECK(false);
				//TestLexer("StringOperations", "Syntax");// TODO : uppend or delete
			}
			BOOST_AUTO_TEST_CASE(LogicOperations)
			{
				//BOOST_CHECK(false);
				TestLexer("LogicOperations", "Syntax");// TODO : uppend
			}
		BOOST_AUTO_TEST_SUITE_END()
		// /\	Operations		/\
		//////////////////////////

		BOOST_AUTO_TEST_CASE(Loops)
		{
			TestLexer("Loops", "Syntax");
		}

	BOOST_AUTO_TEST_SUITE_END()
	// /\/\/\		Syntax								/\/\/\
	//////////////////////////////////////////////////////////


	/*
	BOOST_AUTO_TEST_CASE(RecognizeNumber)
		{
			TestLexer("RecognizeNumber", "Syntax");
		}
		BOOST_AUTO_TEST_CASE(Conditions)
		{
			TestLexer("Conditions", "Syntax");
		}
		BOOST_AUTO_TEST_CASE(Identifier)
		{
			TestLexer("Identifier", "Syntax");
		}
		BOOST_AUTO_TEST_CASE(NotRightIdentifier)// TODO : test neccessary rewrite
		{
			TestLexer("NotRightIdentifier", "Syntax");
		}
	
		
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



		BOOST_AUTO_TEST_SUITE(Keywords)
			BOOST_AUTO_TEST_CASE(Conditions)
			{
				TestLexer("Conditions", "Syntax");
			}

		BOOST_AUTO_TEST_SUITE_END()
		/*
		BOOST_AUTO_TEST_CASE(Types)// TODO : test neccessary rewrite
				{
					TestLexer("Types");
				}
		
		
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
	//////////////////////////////////////////////////////////
	//
	//		Programs
	//
	//////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(Lexer)
		BOOST_AUTO_TEST_CASE(Numbers)
		{
			TestLexer("Numbers", "Lexer");
		}
		BOOST_AUTO_TEST_CASE(Comments)
		{
			TestLexer("Comments", "Lexer");
		}
		BOOST_AUTO_TEST_CASE(Strings)
		{
			TestLexer("Strings", "Lexer");
		}
		BOOST_AUTO_TEST_CASE(Boolean)
		{
			TestLexer("Boolean", "Lexer");
		}
	BOOST_AUTO_TEST_SUITE_END()
	// /\/\/\		Lexer						/\/\/\
	//////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////
	//
	//		Programs
	//
	//////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(Programs)
		BOOST_AUTO_TEST_CASE(HelloWorld)
		{
			//BOOST_CHECK(false);

			TestLexer("HelloWorld", "Programs");
		}
		BOOST_AUTO_TEST_CASE(BubbleSort)
		{
			//BOOST_CHECK(false);

			TestLexer("BubbleSort", "Programs");
		}
		BOOST_AUTO_TEST_CASE(MatrixMultiplication)
		{
			//BOOST_CHECK(false);
			TestLexer("MatrixMultiplication", "Programs");
		}
	BOOST_AUTO_TEST_SUITE_END()
	// /\/\/\		Programs						/\/\/\
	//////////////////////////////////////////////////////////


BOOST_AUTO_TEST_SUITE_END()// OldLexer_

