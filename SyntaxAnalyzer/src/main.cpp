// LRTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "main.h"

int main()
{
	LRTable LRNull;
	LLTable LLNull;


	LRTable LRTable1;
	LLTable LLTable1;
	LLTable LLForTestLR;

	LLTable ruleConstant;
	LLTable expressionRule;
	LLTable variableConstant;
	LLTable functionCallConstant;

	SToken noneToken("NONE", TokensId::TK_NONE);

	
	LRTable1.push_back({ CLRRowElement(startBlockToken, notLRTransition, false), CLRRowElement(expToken, notLRTransition, true),  CLRRowElement(intToken, CTransition(1, &LRTable1, CTransition::TypeTable::LR), true) });
	LRTable1.push_back({    CLRRowElement(plusToken, CTransition(2, &LRTable1, CTransition::TypeTable::LR), Rule(expToken, 1), true), CLRRowElement(minusToken, CTransition(2, &LRTable1, CTransition::TypeTable::LR), Rule(expToken, 1), true), CLRRowElement(endCodeToken, notLRTransition, Rule(expToken, 1), true) });
	LRTable1.push_back({   CLRRowElement(plusToken, CTransition(3, &LRTable1, CTransition::TypeTable::LR), true), CLRRowElement(minusToken, CTransition(3, &LRTable1, CTransition::TypeTable::LR), true) });
	LRTable1.push_back({   CLRRowElement(intToken, CTransition(-1, &LRTable1, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(endBlockToken, CTransition(-1, &LRTable1, CTransition::TypeTable::LR), Rule(expToken, 3), false) });

	LLForTestLR.push_back(CLL1RowElement({ startBlockToken }, false, CTransition(1, &LLForTestLR, CTransition::TypeTable::LL), false, true, false));
	LLForTestLR.push_back(CLL1RowElement({ startBlockToken }, true, CTransition(0, &expressionRule, CTransition::TypeTable::LR), true, true, false));
	LLForTestLR.push_back(CLL1RowElement({ expToken }, false, CTransition(3, &LLForTestLR, CTransition::TypeTable::LL), false, true, false));
	LLForTestLR.push_back(CLL1RowElement({ expToken }, true, CTransition(4, &LLForTestLR, CTransition::TypeTable::LL), true, true, false));
	LLForTestLR.push_back(CLL1RowElement({ endBlockToken }, false, CTransition(5, &LLForTestLR, CTransition::TypeTable::LL), false, true, false));
	LLForTestLR.push_back(CLL1RowElement({ endBlockToken }, true, notLLTransition, true, true, true));


	LLTable1.push_back(CLL1RowElement({ startBlockToken }, false, CTransition(1, &LLTable1, CTransition::TypeTable::LL), false, true, false));
	LLTable1.push_back(CLL1RowElement({ startBlockToken }, true, CTransition(0, &LRTable1, CTransition::TypeTable::LR), true, true, false));
	LLTable1.push_back(CLL1RowElement({ expToken }, false, CTransition(3, &LLTable1, CTransition::TypeTable::LL), false, true, false));
	LLTable1.push_back(CLL1RowElement({ expToken }, true, CTransition(4, &LLTable1, CTransition::TypeTable::LL), true, true, false));
	LLTable1.push_back(CLL1RowElement({ endBlockToken }, false, CTransition(5, &LLTable1, CTransition::TypeTable::LL), false, true, false));
	LLTable1.push_back(CLL1RowElement({ endBlockToken }, true, notLLTransition, true, true, true));


	/*
	//

	expressionRule.push_back({ CLRRowElement(expToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR),  true),  CLRRowElement(intToken, CTransition(1, &expressionRule, CTransition::TypeTable::LR), true) });
	expressionRule.push_back({ CLRRowElement(plusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 1), true), CLRRowElement(minusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 1), true), CLRRowElement(otherToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 1), false) });
	expressionRule.push_back({ CLRRowElement(expToken, CTransition(4, &expressionRule, CTransition::TypeTable::LR),  true),  CLRRowElement(intToken, CTransition(3, &expressionRule, CTransition::TypeTable::LR), true)  });
	expressionRule.push_back({ CLRRowElement(plusToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(minusToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(otherToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false) });
	expressionRule.push_back({ CLRRowElement(plusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(minusToken, CTransition(2, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(otherToken, CTransition(-1, &expressionRule, CTransition::TypeTable::LR), Rule(expToken, 3), false) });

	*/

	ruleConstant.push_back(CLL1RowElement({ intToken }, false, CTransition(1, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
	ruleConstant.push_back(CLL1RowElement({ intToken }, true, notTransition, true, false, true));// 3 - false
	ruleConstant.push_back(CLL1RowElement({ floatToken }, false, CTransition(3, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
	ruleConstant.push_back(CLL1RowElement({ floatToken }, true, notTransition, true, false, true));// 3 - false
	ruleConstant.push_back(CLL1RowElement({ charToken }, false, CTransition(5, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
	ruleConstant.push_back(CLL1RowElement({ charToken }, true, notTransition, true, false, true));// 3 - false
	ruleConstant.push_back(CLL1RowElement({ stringToken }, false, CTransition(7, &ruleConstant, CTransition::TypeTable::LL), true, true, false));
	ruleConstant.push_back(CLL1RowElement({ stringToken }, true, notTransition, true, true, true));

	functionCallConstant.push_back(CLL1RowElement({ idToken }, false, CTransition(1, &functionCallConstant, CTransition::TypeTable::LL), false, true, false));
	functionCallConstant.push_back(CLL1RowElement({ idToken }, true, CTransition(2, &functionCallConstant, CTransition::TypeTable::LL), true, true, false));// 3 - false
	functionCallConstant.push_back(CLL1RowElement({ startListArgumentToken }, false, CTransition(3, &functionCallConstant, CTransition::TypeTable::LL), false, true, false));
	functionCallConstant.push_back(CLL1RowElement({ startListArgumentToken }, true, CTransition(4, &functionCallConstant, CTransition::TypeTable::LL), true, true, false));// 3 - false
	functionCallConstant.push_back(CLL1RowElement({ endListArgumentToken }, false, CTransition(5, &functionCallConstant, CTransition::TypeTable::LL), false, true, false));
	functionCallConstant.push_back(CLL1RowElement({ endListArgumentToken }, true, CTransition(6, &functionCallConstant, CTransition::TypeTable::LL), true, true, true));// 3 - false


	expressionRule.push_back(CLL1RowElement({ intToken }, false, CTransition(1, &expressionRule, CTransition::TypeTable::LL), false, false, false));
	expressionRule.push_back(CLL1RowElement({ intToken }, true, CTransition(14, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
	expressionRule.push_back(CLL1RowElement({ floatToken }, false, CTransition(3, &expressionRule, CTransition::TypeTable::LL), false, false, false));
	expressionRule.push_back(CLL1RowElement({ floatToken }, true, CTransition(14, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
	expressionRule.push_back(CLL1RowElement({ charToken }, false, CTransition(5, &expressionRule, CTransition::TypeTable::LL), false, false, false));
	expressionRule.push_back(CLL1RowElement({ charToken }, true, CTransition(14, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
	expressionRule.push_back(CLL1RowElement({ stringToken }, false, CTransition(7, &expressionRule, CTransition::TypeTable::LL), false, false, false));
	expressionRule.push_back(CLL1RowElement({ stringToken }, true, CTransition(14, &expressionRule, CTransition::TypeTable::LL), true, false, false));
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
	expressionRule.push_back(CLL1RowElement({ logicOrToken }, true, CTransition(26, &expressionRule, CTransition::TypeTable::LL), true, false, false));// 3 - false
	expressionRule.push_back(CLL1RowElement({ endCodeToken }, false, CTransition(27, &expressionRule, CTransition::TypeTable::LL), false, true, false));// 3 - false
	expressionRule.push_back(CLL1RowElement({ endCodeToken }, true, notLLTransition, false, true, true));// 3 - false


	variableConstant.push_back(CLL1RowElement({ idToken }, false, CTransition(1, &variableConstant, CTransition::TypeTable::LL), false, false, false));
	variableConstant.push_back(CLL1RowElement({ idToken }, true, CTransition(-1, &variableConstant, CTransition::TypeTable::LL), true, true, true));// 3 - false


	auto walker = HybridWalker(&LRTable1, &LLTable1, HybridWalker::State::LLCheck);
	std::vector<SToken> inputSeq = { startBlockToken, intToken, plusToken, intToken,  endBlockToken };//plusToken, intToken,

	auto constantRuleWalker = HybridWalker(&LRNull, &expressionRule, HybridWalker::State::LLCheck);
	std::vector<SToken> constantSeq = {
		intToken, plusToken, intToken
	};

	try
	{
		//if (walker.CheckInputSequence(inputSeq))
		if (constantRuleWalker.CheckInputSequence(constantSeq))
		{
			std::cout << "Hybrid Success!" << std::endl;
		}
		else
		{
			std::cout << "Hybrid Error!" << std::endl;
		}
	}
	catch (std::runtime_error & err)
	{
		std::cout << err.what();
	}

	

    return 0;
}

