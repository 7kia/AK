// Lab2-1Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "FunctionsForTests.h"
#include "TestsOld.h"

using namespace std;

struct OldLexer_ : public TestNameFiles_
{
	const std::string nameFormatFiles = ".txt";
	const std::string nameCodeFile = "testProgram";
	const std::string nameErrorFile = "errorProgram";
	const std::string nameOutputFile = "outputProgram";
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
			const std::string suffixCheckFiles = "1";

			BOOST_REQUIRE_NO_THROW(TestLexer(nameCodeFile + suffixCheckFiles + nameFormatFiles
												, nameErrorFile + suffixCheckFiles + nameFormatFiles
												, nameOutputFile + suffixCheckFiles + nameFormatFiles));

			CompareFiles(nameOutputFile + suffixCheckFiles + nameFormatFiles
						, PATH_RIGHT_DATA + nameOutputFile + suffixCheckFiles + nameFormatFiles);

			CompareFiles(nameErrorFile + suffixCheckFiles + nameFormatFiles
				, PATH_RIGHT_DATA + nameErrorFile + suffixCheckFiles + nameFormatFiles);

		}

	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()// OldLexer_

