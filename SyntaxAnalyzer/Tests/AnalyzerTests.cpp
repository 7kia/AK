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

	std::vector<SToken> sequenceForExp1 = { intToken };
	std::vector<SToken> sequenceForExp2 = { intToken
	};
	std::vector<SToken> sequenceForExp3 = { intToken
		, };
	std::vector<SToken> sequenceForExp4 = {
		intToken
	};


	LLTable ruleConstant;
	LLTable variableConstant;
	LLTable functionCallConstant;
	LLTable expressionRule;
	LLTable expressionRulе;

	LLTable typeReferenceRule;
	LLTable statementRule;

	Rules_()
	{
		LLForTestLR.push_back(CLL1RowElement({ startBlockToken }, false, CTransition(1, &LLForTestLR, CTransition::TypeTable::LL), false, true, false));
		LLForTestLR.push_back(CLL1RowElement({ startBlockToken }, true, CTransition(0, &expressionRule, CTransition::TypeTable::LR), true, true, false));
		LLForTestLR.push_back(CLL1RowElement({ expToken }, false, CTransition(3, &LLForTestLR, CTransition::TypeTable::LL), false, true, false));
		LLForTestLR.push_back(CLL1RowElement({ expToken }, true, CTransition(4, &LLForTestLR, CTransition::TypeTable::LL), true, true, false));
		LLForTestLR.push_back(CLL1RowElement({ endBlockToken }, false, CTransition(5, &LLForTestLR, CTransition::TypeTable::LL), false, true, false));
		LLForTestLR.push_back(CLL1RowElement({ endBlockToken }, true, notLLTransition, true, true, true));

		expressionRulе.push_back(CLL1RowElement({ intToken }, false, CTransition(1, &expressionRulе, CTransition::TypeTable::LL), false, false, false));
		expressionRulе.push_back(CLL1RowElement({ intToken }, true, CTransition(-1, &expressionRulе, CTransition::TypeTable::LL), true, true, true));// 3 - false


		ruleConstant.push_back(CLL1RowElement({ intToken }, false, CTransition(1, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ intToken }, true, notLLTransition, true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ floatToken }, false, CTransition(3, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ floatToken }, true, notLLTransition, true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ charToken }, false, CTransition(5, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ charToken }, true, notLLTransition, true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ stringToken }, false, CTransition(7, &ruleConstant, CTransition::TypeTable::LL), true, true, false));
		ruleConstant.push_back(CLL1RowElement({ stringToken }, true, notLLTransition, true, true, true));


		variableConstant.push_back(CLL1RowElement({ idToken }, false, CTransition(1, &variableConstant, CTransition::TypeTable::LL), false, false, false));
		variableConstant.push_back(CLL1RowElement({ idToken }, true, CTransition(-1, &variableConstant, CTransition::TypeTable::LL), true, true, true));// 3 - false

		functionCallConstant.push_back(CLL1RowElement({ idToken }, false, CTransition(1, &functionCallConstant, CTransition::TypeTable::LL), false, true, false));
		functionCallConstant.push_back(CLL1RowElement({ idToken }, true, CTransition(2, &functionCallConstant, CTransition::TypeTable::LL), true, true, false));// 3 - false
		functionCallConstant.push_back(CLL1RowElement({ startListArgumentToken }, false, CTransition(3, &functionCallConstant, CTransition::TypeTable::LL), false, true, false));
		functionCallConstant.push_back(CLL1RowElement({ startListArgumentToken }, true, CTransition(4, &functionCallConstant, CTransition::TypeTable::LL), true, true, false));// 3 - false
		functionCallConstant.push_back(CLL1RowElement({ endListArgumentToken }, false, CTransition(5, &functionCallConstant, CTransition::TypeTable::LL), true, true, false));
		functionCallConstant.push_back(CLL1RowElement({ endListArgumentToken }, true, notLLTransition, true, true, true));// 3 - false

		/*
		//LR variant
		expressionRule.push_back({ CLRRowElement(expToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR),  true),  CLRRowElement(intToken, CTransition(1, &expressionRule, CTransition::TypeTable::LR), true) });
		expressionRule.push_back({ CLRRowElement(plusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 1), true), CLRRowElement(minusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 1), true), CLRRowElement(otherToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 1), false) });
		expressionRule.push_back({ CLRRowElement(expToken, CTransition(4, &expressionRule, CTransition::TypeTable::LR),  true),  CLRRowElement(intToken, CTransition(3, &expressionRule, CTransition::TypeTable::LR), true) });
		expressionRule.push_back({ CLRRowElement(plusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(minusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(otherToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false) });
		expressionRule.push_back({ CLRRowElement(plusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(minusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(otherToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false) });

		//*/
		ruleConstant.push_back(CLL1RowElement({ intToken }, false, CTransition(1, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ intToken }, true, notLLTransition, true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ floatToken }, false, CTransition(3, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ floatToken }, true, notLLTransition, true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ charToken }, false, CTransition(5, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
		ruleConstant.push_back(CLL1RowElement({ charToken }, true, notLLTransition, true, false, true));// 3 - false
		ruleConstant.push_back(CLL1RowElement({ stringToken }, false, CTransition(7, &ruleConstant, CTransition::TypeTable::LL), true, true, false));
		ruleConstant.push_back(CLL1RowElement({ stringToken }, true, notLLTransition, true, true, true));

		// constant
		expressionRule.push_back(CLL1RowElement({ intToken }, false, CTransition(1, &expressionRule, CTransition::TypeTable::LL), false, false, false));
		expressionRule.push_back(CLL1RowElement({ intToken }, true, CTransition(14, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		expressionRule.push_back(CLL1RowElement({ floatToken }, false, CTransition(3, &expressionRule, CTransition::TypeTable::LL), false, false, false));
		expressionRule.push_back(CLL1RowElement({ floatToken }, true, CTransition(14, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		expressionRule.push_back(CLL1RowElement({ charToken }, false, CTransition(5, &expressionRule, CTransition::TypeTable::LL), false, false, false));
		expressionRule.push_back(CLL1RowElement({ charToken }, true, CTransition(14, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		expressionRule.push_back(CLL1RowElement({ stringToken }, false, CTransition(7, &expressionRule, CTransition::TypeTable::LL), true, true, false));
		expressionRule.push_back(CLL1RowElement({ stringToken }, true, CTransition(14, &expressionRule, CTransition::TypeTable::LL), true, true, false));
		expressionRule.push_back(CLL1RowElement({ idToken }, false, CTransition(1, &expressionRule, CTransition::TypeTable::LL), false, false, false));
		expressionRule.push_back(CLL1RowElement({ idToken }, true, CTransition(14, &expressionRule, CTransition::TypeTable::LL), true, true, false));// 3 - false
		expressionRule.push_back(CLL1RowElement({ startListToken }, false, CTransition(1, &expressionRule, CTransition::TypeTable::LL), false, false, false));
		expressionRule.push_back(CLL1RowElement({ startListToken }, true, CTransition(0, &expressionRule, CTransition::TypeTable::LL), true, true, false));// 3 - false
		expressionRule.push_back(CLL1RowElement({ endListToken }, false, CTransition(1, &expressionRule, CTransition::TypeTable::LL), true, true, false));
		expressionRule.push_back(CLL1RowElement({ endListToken }, true, notLLTransition, true, true, true));// 3 - false
		expressionRule.push_back(CLL1RowElement({ plusToken }, false, CTransition(15, &expressionRule, CTransition::TypeTable::LL), false, false, false));
		expressionRule.push_back(CLL1RowElement({ plusToken }, true, CTransition(0, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		expressionRule.push_back(CLL1RowElement({ minusToken }, false, CTransition(17, &expressionRule, CTransition::TypeTable::LL), false, false, false));
		expressionRule.push_back(CLL1RowElement({ minusToken }, true, CTransition(0, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		expressionRule.push_back(CLL1RowElement({ devideToken }, false, CTransition(19, &expressionRule, CTransition::TypeTable::LL), false, false, false));
		expressionRule.push_back(CLL1RowElement({ devideToken }, true, CTransition(0, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		expressionRule.push_back(CLL1RowElement({ starToken }, false, CTransition(21, &expressionRule, CTransition::TypeTable::LL), false, false, false));
		expressionRule.push_back(CLL1RowElement({ starToken }, true, CTransition(0, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		expressionRule.push_back(CLL1RowElement({ logicAndToken }, false, CTransition(23, &expressionRule, CTransition::TypeTable::LL), false, false, false));
		expressionRule.push_back(CLL1RowElement({ logicAndToken }, true, CTransition(0, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		expressionRule.push_back(CLL1RowElement({ logicOrToken }, false, CTransition(25, &expressionRule, CTransition::TypeTable::LL), false, false, false));
		expressionRule.push_back(CLL1RowElement({ logicOrToken }, true, CTransition(0, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false

		typeReferenceRule.push_back(CLL1RowElement({ intTypeToken }, false, CTransition(1, &typeReferenceRule, CTransition::TypeTable::LL), false, false, false));
		typeReferenceRule.push_back(CLL1RowElement({ intTypeToken }, true, notLLTransition, true, false, true));// 3 - false
		typeReferenceRule.push_back(CLL1RowElement({ floatTypeToken }, false, CTransition(3, &typeReferenceRule, CTransition::TypeTable::LL), false, false, false));
		typeReferenceRule.push_back(CLL1RowElement({ floatTypeToken }, true, notLLTransition, true, false, true));// 3 - false
		typeReferenceRule.push_back(CLL1RowElement({ charTypeToken }, false, CTransition(5, &typeReferenceRule, CTransition::TypeTable::LL), false, false, false));
		typeReferenceRule.push_back(CLL1RowElement({ charTypeToken }, true, notLLTransition, true, false, true));// 3 - false
		typeReferenceRule.push_back(CLL1RowElement({ logicTypeToken }, false, CTransition(7, &typeReferenceRule, CTransition::TypeTable::LL), false, false, false));
		typeReferenceRule.push_back(CLL1RowElement({ logicTypeToken }, true, notLLTransition, true, false, true));// 3 - false
		typeReferenceRule.push_back(CLL1RowElement({ stringTypeToken }, false, CTransition(9, &typeReferenceRule, CTransition::TypeTable::LL), true, true, false));
		typeReferenceRule.push_back(CLL1RowElement({ stringTypeToken }, true, notLLTransition, true, true, true));


		// statementRule
		statementRule.push_back(CLL1RowElement({ printToken }, false, CTransition(1, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ printToken }, true, CTransition(2, &statementRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		
		statementRule.push_back(CLL1RowElement({ readToken }, false, CTransition(3, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ readToken }, true, CTransition(4, &statementRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		
		statementRule.push_back(CLL1RowElement({ intTypeToken }, false, CTransition(1, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ intTypeToken }, true, notLLTransition, true, false, true));// 3 - false
		statementRule.push_back(CLL1RowElement({ floatTypeToken }, false, CTransition(3, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ floatTypeToken }, true, notLLTransition, true, false, true));// 3 - false
		statementRule.push_back(CLL1RowElement({ charTypeToken }, false, CTransition(5, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ charTypeToken }, true, notLLTransition, true, false, true));// 3 - false
		statementRule.push_back(CLL1RowElement({ logicTypeToken }, false, CTransition(7, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ logicTypeToken }, true, notLLTransition, true, false, true));// 3 - false
		statementRule.push_back(CLL1RowElement({ stringTypeToken }, false, CTransition(9, &statementRule, CTransition::TypeTable::LL), true, true, false));
		statementRule.push_back(CLL1RowElement({ stringTypeToken }, true, notLLTransition, true, true, true));

		statementRule.push_back(CLL1RowElement({ idToken }, false, CTransition(1, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ idToken }, true, CTransition(14, &statementRule, CTransition::TypeTable::LL), true, true, false));// 3 - false

		statementRule.push_back(CLL1RowElement({ ifToken }, false, CTransition(1, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ ifToken }, true, CTransition(14, &statementRule, CTransition::TypeTable::LL), true, true, false));// 3 - false

		statementRule.push_back(CLL1RowElement({ returnToken }, false, CTransition(1, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ returnToken }, true, CTransition(14, &statementRule, CTransition::TypeTable::LL), true, true, false));// 3 - false


		statementRule.push_back(CLL1RowElement({ whileToken }, false, CTransition(1, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ whileToken }, true, CTransition(14, &statementRule, CTransition::TypeTable::LL), true, true, false));// 3 - false

		// ( exp )
		statementRule.push_back(CLL1RowElement({ startBlockToken }, false, CTransition(1, &statementRule, CTransition::TypeTable::LL), false, true, false));
		statementRule.push_back(CLL1RowElement({ startBlockToken }, true, CTransition(0, &statementRule, CTransition::TypeTable::LR), true, true, false));
		
		statementRule.push_back(CLL1RowElement({ intToken }, false, CTransition(1, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ intToken }, true, CTransition(14, &statementRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		statementRule.push_back(CLL1RowElement({ floatToken }, false, CTransition(3, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ floatToken }, true, CTransition(14, &statementRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		statementRule.push_back(CLL1RowElement({ charToken }, false, CTransition(5, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ charToken }, true, CTransition(14, &statementRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		statementRule.push_back(CLL1RowElement({ stringToken }, false, CTransition(7, &statementRule, CTransition::TypeTable::LL), true, true, false));
		statementRule.push_back(CLL1RowElement({ stringToken }, true, CTransition(14, &statementRule, CTransition::TypeTable::LL), true, true, false));
		statementRule.push_back(CLL1RowElement({ idToken }, false, CTransition(1, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ idToken }, true, CTransition(14, &statementRule, CTransition::TypeTable::LL), true, true, false));// 3 - false
		statementRule.push_back(CLL1RowElement({ startListToken }, false, CTransition(1, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ startListToken }, true, CTransition(0, &statementRule, CTransition::TypeTable::LL), true, true, false));// 3 - false
		statementRule.push_back(CLL1RowElement({ endListToken }, false, CTransition(1, &statementRule, CTransition::TypeTable::LL), true, true, false));
		statementRule.push_back(CLL1RowElement({ endListToken }, true, notLLTransition, true, true, true));// 3 - false
		statementRule.push_back(CLL1RowElement({ plusToken }, false, CTransition(15, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ plusToken }, true, CTransition(0, &statementRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		statementRule.push_back(CLL1RowElement({ minusToken }, false, CTransition(17, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ minusToken }, true, CTransition(0, &statementRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		statementRule.push_back(CLL1RowElement({ devideToken }, false, CTransition(19, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ devideToken }, true, CTransition(0, &statementRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		statementRule.push_back(CLL1RowElement({ starToken }, false, CTransition(21, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ starToken }, true, CTransition(0, &statementRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		statementRule.push_back(CLL1RowElement({ logicAndToken }, false, CTransition(23, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ logicAndToken }, true, CTransition(0, &statementRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
		statementRule.push_back(CLL1RowElement({ logicOrToken }, false, CTransition(25, &statementRule, CTransition::TypeTable::LL), false, false, false));
		statementRule.push_back(CLL1RowElement({ logicOrToken }, true, notLLTransition, true, false, false));// 3 - false
		
		statementRule.push_back(CLL1RowElement({ endBlockToken }, false, CTransition(5, &LLForTestLR, CTransition::TypeTable::LL), false, true, false));
		statementRule.push_back(CLL1RowElement({ endBlockToken }, true, notLLTransition, true, true, true));

		functionCallConstant.push_back(CLL1RowElement({ elseToken }, false, CTransition(3, &functionCallConstant, CTransition::TypeTable::LL), false, true, false));
		functionCallConstant.push_back(CLL1RowElement({ elseToken }, true, CTransition(4, &functionCallConstant, CTransition::TypeTable::LL), true, true, false));// 3 - false
		// next block
		functionCallConstant.push_back(CLL1RowElement({ endListArgumentToken }, false, CTransition(5, &functionCallConstant, CTransition::TypeTable::LL), true, true, false));
		functionCallConstant.push_back(CLL1RowElement({ endListArgumentToken }, true, notLLTransition, true, true, true));// 3 - false


	}
};

BOOST_FIXTURE_TEST_SUITE(Rules, Rules_)

	struct Constant_ : public Rules_
	{
		HybridWalker constantRuleWalker;

		Constant_()
			: constantRuleWalker(&LRNull, &ruleConstant, HybridWalker::State::LLCheck)
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
			: walker(&LRNull, &variableConstant, HybridWalker::State::LLCheck)
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
			: walker(&LRNull, &functionCallConstant, HybridWalker::State::LLCheck)
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
		}// TODO : 
	BOOST_AUTO_TEST_SUITE_END()// FunctionCall


	struct Expression_ : public Rules_
	{
		HybridWalker walker;

		Expression_()
			: walker(&LRNull, &expressionRulе, HybridWalker::State::LLCheck)
		{
			LLForTestLR[1].m_transition = CTransition(0, &expressionRule, CTransition::TypeTable::LR);
		};
	};
	BOOST_FIXTURE_TEST_SUITE(Expression, Expression_)
		BOOST_AUTO_TEST_CASE(One_int)
		{
			std::vector<SToken> sequenceForЕxp1 = { intToken };


			BOOST_CHECK(walker.CheckInputSequence(sequenceForExp1));
		}
		BOOST_AUTO_TEST_CASE(Int_plus_int)
		{
			std::vector<SToken> sequenceForЕxp2 = { intToken, plusToken, intToken
			};

			BOOST_CHECK(walker.CheckInputSequence(sequenceForExp2));
		}
		BOOST_AUTO_TEST_CASE(Int_minus_int)
		{
			std::vector<SToken> sequenceForЕxp3 = { intToken, minusToken, intToken
				, };

			BOOST_CHECK(walker.CheckInputSequence(sequenceForExp3));
		}
		BOOST_AUTO_TEST_CASE(Exp_and_int)
		{
			std::vector<SToken> sequenceForЕxp4 = {
				intToken, plusToken, intToken, plusToken, intToken
			};

			BOOST_CHECK(walker.CheckInputSequence(sequenceForExp4));
		}
	BOOST_AUTO_TEST_SUITE_END()// Expression

BOOST_AUTO_TEST_SUITE_END()// Rules_



BOOST_AUTO_TEST_SUITE_END()// RuleTests