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
	LLTable LLForTestLR;


	LLTable ruleConstant;
	LLTable variableConstant;
	LLTable functionCallConstant;
	LRTable expressionRule;

	Rules_()
	{
		LLForTestLR.push_back(CLL1RowElement({ startBlockToken }, false, CTransition(1, &LLForTestLR, CTransition::TypeTable::LL), false, true, false));
		LLForTestLR.push_back(CLL1RowElement({ startBlockToken }, true, CTransition(0, &expressionRule, CTransition::TypeTable::LR), true, true, false));
		LLForTestLR.push_back(CLL1RowElement({ expToken }, false, CTransition(3, &LLForTestLR, CTransition::TypeTable::LL), false, true, false));
		LLForTestLR.push_back(CLL1RowElement({ expToken }, true, CTransition(4, &LLForTestLR, CTransition::TypeTable::LL), true, true, false));
		LLForTestLR.push_back(CLL1RowElement({ endBlockToken }, false, CTransition(5, &LLForTestLR, CTransition::TypeTable::LL), false, true, false));
		LLForTestLR.push_back(CLL1RowElement({ endBlockToken }, true, notLLTransition, true, true, true));

		ruleConstant.push_back(CLL1RowElement({ intToken }, false, CTransition(1, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ intToken }, true, CTransition(2, &ruleConstant, CTransition::TypeTable::LL), true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ floatToken }, false, CTransition(3, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ floatToken }, true, CTransition(4, &ruleConstant, CTransition::TypeTable::LL), true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ charToken }, false, CTransition(5, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ charToken }, true, CTransition(6, &ruleConstant, CTransition::TypeTable::LL), true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ stringToken }, false, CTransition(7, &ruleConstant, CTransition::TypeTable::LL), true, true, false));
		ruleConstant.push_back(CLL1RowElement({ stringToken }, true, notLLTransition, true, true, false));


		variableConstant.push_back(CLL1RowElement({ idToken }, false, CTransition(1, &variableConstant, CTransition::TypeTable::LL), false, false, false));
		variableConstant.push_back(CLL1RowElement({ idToken }, true, CTransition(-1, &variableConstant, CTransition::TypeTable::LL), true, true, true));// 3 - false

		functionCallConstant.push_back(CLL1RowElement({ idToken }, false, CTransition(1, &variableConstant, CTransition::TypeTable::LL), false, true, false));
		functionCallConstant.push_back(CLL1RowElement({ idToken }, true, CTransition(2, &variableConstant, CTransition::TypeTable::LL), true, true, false));// 3 - false
		functionCallConstant.push_back(CLL1RowElement({ startListArgumentToken }, false, CTransition(3, &variableConstant, CTransition::TypeTable::LL), false, true, false));
		functionCallConstant.push_back(CLL1RowElement({ startListArgumentToken }, true, CTransition(4, &variableConstant, CTransition::TypeTable::LL), true, true, false));// 3 - false
		functionCallConstant.push_back(CLL1RowElement({ endListArgumentToken }, false, CTransition(5, &variableConstant, CTransition::TypeTable::LL), false, true, false));
		functionCallConstant.push_back(CLL1RowElement({ endListArgumentToken }, true, CTransition(6, &variableConstant, CTransition::TypeTable::LL), true, true, true));// 3 - false

		expressionRule.push_back({ CLRRowElement(expToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR),  true),  CLRRowElement(intToken, CTransition(1, &expressionRule, CTransition::TypeTable::LR), true) });
		expressionRule.push_back({ CLRRowElement(plusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 1), true), CLRRowElement(minusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 1), true), CLRRowElement(otherToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 1), false) });
		expressionRule.push_back({ CLRRowElement(expToken, CTransition(4, &expressionRule, CTransition::TypeTable::LR),  true),  CLRRowElement(intToken, CTransition(3, &expressionRule, CTransition::TypeTable::LR), true) });
		expressionRule.push_back({ CLRRowElement(plusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(minusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(otherToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false) });
		expressionRule.push_back({ CLRRowElement(plusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(minusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(otherToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false) });

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
			
			BOOST_CHECK(constantRuleWalker.CheckInputSequence(constantSeq));
		}
		BOOST_AUTO_TEST_CASE(Float)
		{
			std::vector<SToken> constantSeq = { floatToken };

			BOOST_CHECK(constantRuleWalker.CheckInputSequence(constantSeq));
		}
		BOOST_AUTO_TEST_CASE(Char)
		{
			std::vector<SToken> constantSeq = { charToken };

			BOOST_CHECK(constantRuleWalker.CheckInputSequence(constantSeq));
		}
		BOOST_AUTO_TEST_CASE(String)
		{
			std::vector<SToken> constantSeq = { stringToken };

			BOOST_CHECK(constantRuleWalker.CheckInputSequence(constantSeq));
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
		BOOST_AUTO_TEST_CASE(Id)
		{
			std::vector<SToken> constantSeq = { idToken };

			BOOST_CHECK(walker.CheckInputSequence(constantSeq));
		}
	BOOST_AUTO_TEST_SUITE_END()// Variable

	struct FunctionCall_ : public Rules_
	{
		HybridWalker walker;

		FunctionCall_()
			: walker(LRNull, functionCallConstant, HybridWalker::State::LLCheck)
		{
		};
	};
	BOOST_FIXTURE_TEST_SUITE(FunctionCall, FunctionCall_)
		BOOST_AUTO_TEST_CASE(Incorrect_form_Not_arguments)
		{
			std::vector<SToken> constantSeq = { idToken, startListArgumentToken };

			BOOST_CHECK_THROW(walker.CheckInputSequence(constantSeq), CLLUnexpectedSymbolsError);
		}
		BOOST_AUTO_TEST_CASE(Not_arguments)
		{
			std::vector<SToken> constantSeq = { idToken, startListArgumentToken, endListArgumentToken};

			BOOST_CHECK(walker.CheckInputSequence(constantSeq));
		}
	BOOST_AUTO_TEST_SUITE_END()// FunctionCall


	struct Expression_ : public Rules_
	{
		HybridWalker walker;

		Expression_()
			: walker(expressionRule, LLForTestLR, HybridWalker::State::LLCheck)
		{
			LLForTestLR[1].m_transition = CTransition(0, &expressionRule, CTransition::TypeTable::LR);
		};
	};
	BOOST_FIXTURE_TEST_SUITE(Expression, Expression_)
		BOOST_AUTO_TEST_CASE(One_int)
		{
			std::vector<SToken> constantSeq = { startBlockToken
												, intToken
												, endBlockToken
			};

			BOOST_CHECK(walker.CheckInputSequence(constantSeq));
		}
		BOOST_AUTO_TEST_CASE(Int_plus_int)
		{
			std::vector<SToken> constantSeq = { startBlockToken
												, intToken, plusToken, intToken
												, endBlockToken };

			BOOST_CHECK(walker.CheckInputSequence(constantSeq));
		}
		BOOST_AUTO_TEST_CASE(Int_minus_int)
		{
			std::vector<SToken> constantSeq = { startBlockToken
												, intToken, minusToken, intToken
												, endBlockToken };

			BOOST_CHECK(walker.CheckInputSequence(constantSeq));
		}
		BOOST_AUTO_TEST_CASE(Exp_and_int)
		{
			std::vector<SToken> constantSeq = { startBlockToken
											, intToken, plusToken, intToken, plusToken, intToken
											, endBlockToken };

			BOOST_CHECK(walker.CheckInputSequence(constantSeq));
		}
	BOOST_AUTO_TEST_SUITE_END()// Expression

BOOST_AUTO_TEST_SUITE_END()// Rules_



BOOST_AUTO_TEST_SUITE_END()// RuleTests