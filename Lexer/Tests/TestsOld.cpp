// Lab2-1Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "FunctionsForTests.h"
#include "TestsOld.h"

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
	BOOST_AUTO_TEST_SUITE(big_tests)
		BOOST_AUTO_TEST_CASE(first)
		{
			TestLexer("1");
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()// OldLexer_

