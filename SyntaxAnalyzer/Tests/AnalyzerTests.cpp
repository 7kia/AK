// Lab2-1Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../src/main.h"

BOOST_AUTO_TEST_SUITE(RuleTests)

struct Rules_
{
	LRTable LRNull;
	LLTable LLNull;

	// Rules
	LLTable ruleConstant;

	Rules_()
	{
		ruleConstant.push_back(CLL1RowElement({ intToken }, false, CTransition(1, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ intToken }, true, CTransition(2, &ruleConstant, CTransition::TypeTable::LL), true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ floatToken }, false, CTransition(3, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ floatToken }, true, CTransition(4, &ruleConstant, CTransition::TypeTable::LL), true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ charToken }, false, CTransition(5, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ charToken }, true, CTransition(6, &ruleConstant, CTransition::TypeTable::LL), true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ stringToken }, false, CTransition(7, &ruleConstant, CTransition::TypeTable::LL), false, true, false));
		ruleConstant.push_back(CLL1RowElement({ stringToken }, true, notLLTransition, true, true, false));


	}
};

BOOST_FIXTURE_TEST_SUITE(Rules, Rules_)

	struct Constant_ : public Rules_
	{
		HybridWalker constantRuleWalker;

		Constant_()
			: constantRuleWalker(LRNull, ruleConstant, HybridWalker::State::LLCheck)
		{
		};
	};
	BOOST_FIXTURE_TEST_SUITE(Constant, Constant_)
		BOOST_AUTO_TEST_CASE(Integer)
		{
			std::vector<SToken> constantSeq = { intToken };
			
			BOOST_NOEXCEPT(constantRuleWalker.CheckInputSequence(constantSeq));
		}
	BOOST_AUTO_TEST_SUITE_END()// Constant




BOOST_AUTO_TEST_SUITE_END()// Rules_



BOOST_AUTO_TEST_SUITE_END()// RuleTests