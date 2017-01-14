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
	LLTable variableConstant;

	Rules_()
	{
		ruleConstant.push_back(CLL1RowElement({ intToken }, false, CTransition(1, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ intToken }, true, CTransition(2, &ruleConstant, CTransition::TypeTable::LL), true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ floatToken }, false, CTransition(3, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ floatToken }, true, CTransition(4, &ruleConstant, CTransition::TypeTable::LL), true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ charToken }, false, CTransition(5, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ charToken }, true, CTransition(6, &ruleConstant, CTransition::TypeTable::LL), true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ stringToken }, false, CTransition(7, &ruleConstant, CTransition::TypeTable::LL), true, true, false));
		ruleConstant.push_back(CLL1RowElement({ stringToken }, true, notLLTransition, true, true, false));


		variableConstant.push_back(CLL1RowElement({ idToken }, false, CTransition(1, &variableConstant, CTransition::TypeTable::LL), false, false, false));
		variableConstant.push_back(CLL1RowElement({ idToken }, true, CTransition(2, &variableConstant, CTransition::TypeTable::LL), true, true, true));// 3 - false

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
		BOOST_AUTO_TEST_CASE(Float)
		{
			std::vector<SToken> constantSeq = { floatToken };

			BOOST_NOEXCEPT(constantRuleWalker.CheckInputSequence(constantSeq));
		}
		BOOST_AUTO_TEST_CASE(Char)
		{
			std::vector<SToken> constantSeq = { charToken };

			BOOST_NOEXCEPT(constantRuleWalker.CheckInputSequence(constantSeq));
		}
		BOOST_AUTO_TEST_CASE(String)
		{
			std::vector<SToken> constantSeq = { stringToken };

			BOOST_NOEXCEPT(constantRuleWalker.CheckInputSequence(constantSeq));
		}
	BOOST_AUTO_TEST_SUITE_END()// Constant

	struct Variable_ : public Rules_
	{
		HybridWalker walker;

		Variable_()
			: walker(LRNull, variableConstant, HybridWalker::State::LLCheck)
		{
		};
	};

	BOOST_FIXTURE_TEST_SUITE(Variable, Variable_)
		BOOST_AUTO_TEST_CASE(String)
		{
			std::vector<SToken> constantSeq = { idToken };

			BOOST_NOEXCEPT(walker.CheckInputSequence(constantSeq));
		}
	BOOST_AUTO_TEST_SUITE_END()// Variable


BOOST_AUTO_TEST_SUITE_END()// Rules_



BOOST_AUTO_TEST_SUITE_END()// RuleTests