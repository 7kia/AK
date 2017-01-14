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

	LLTable ruleConstant;

	SToken noneToken("NONE", TokensId::TK_NONE);
	SToken endCodeToken("End code", TokensId::TK_END_CODE);
	SToken expToken("exp", TokensId::RULE_EXPRESSION);
	SToken plusToken("+", TokensId::TK_PLUS);
	SToken minusToken("-", TokensId::TK_MINUS);
	SToken startBlockToken("{", TokensId::TK_LEFT_BRACE);
	SToken endBlockToken("}", TokensId::TK_RIGHT_BRACE);

	
	LRTable1.push_back({ CLRRowElement(startBlockToken, notLRTransition, false), CLRRowElement(expToken, notLRTransition, true),  CLRRowElement(intToken, CTransition(1, &LRTable1, CTransition::TypeTable::LR), true) });
	LRTable1.push_back({ CLRRowElement(startBlockToken, notLRTransition, false), CLRRowElement(expToken, notLRTransition, false), CLRRowElement(intToken, notLRTransition, false), CLRRowElement(plusToken, CTransition(2, &LRTable1, CTransition::TypeTable::LR), Rule(expToken, 1), true), CLRRowElement(minusToken, CTransition(2, &LRTable1, CTransition::TypeTable::LR), Rule(expToken, 1), true), CLRRowElement(endCodeToken, notLRTransition, Rule(expToken, 1), true) });
	LRTable1.push_back({ CLRRowElement(startBlockToken, notLRTransition, false), CLRRowElement(expToken, notLRTransition, false), CLRRowElement(intToken, CTransition(3, &LRTable1, CTransition::TypeTable::LR), true) });
	LRTable1.push_back({ CLRRowElement(startBlockToken, notLRTransition, false), CLRRowElement(expToken, notLRTransition, false), CLRRowElement(intToken, CTransition(-1, &LRTable1, CTransition::TypeTable::LR), Rule(expToken, 3), false), CLRRowElement(endBlockToken, CTransition(-1, &LRTable1, CTransition::TypeTable::LR), Rule(expToken, 3), false) });



	LLTable1.push_back(CLL1RowElement({ startBlockToken }, false, CTransition(1, &LLTable1, CTransition::TypeTable::LL), false, true, false));
	LLTable1.push_back(CLL1RowElement({ startBlockToken }, true, CTransition(0, &LRTable1, CTransition::TypeTable::LR), true, true, false));
	LLTable1.push_back(CLL1RowElement({ expToken }, false, CTransition(3, &LLTable1, CTransition::TypeTable::LL), false, true, false));
	LLTable1.push_back(CLL1RowElement({ expToken }, true, CTransition(4, &LLTable1, CTransition::TypeTable::LL), true, true, false));
	LLTable1.push_back(CLL1RowElement({ endBlockToken }, false, CTransition(5, &LLTable1, CTransition::TypeTable::LL), false, true, false));
	LLTable1.push_back(CLL1RowElement({ endBlockToken }, true, notLLTransition, true, true, true));

	ruleConstant.push_back(CLL1RowElement({ intToken }, false, CTransition(1, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
	ruleConstant.push_back(CLL1RowElement({ intToken }, true, CTransition(2, &ruleConstant, CTransition::TypeTable::LL), true, false, true));// 3 - false
	ruleConstant.push_back(CLL1RowElement({ floatToken }, false, CTransition(3, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
	ruleConstant.push_back(CLL1RowElement({ floatToken }, true, CTransition(4, &ruleConstant, CTransition::TypeTable::LL), true, false, true));// 3 - false
	ruleConstant.push_back(CLL1RowElement({ charToken }, false, CTransition(5, &ruleConstant, CTransition::TypeTable::LL), false, false, false));
	ruleConstant.push_back(CLL1RowElement({ charToken }, true, CTransition(6, &ruleConstant, CTransition::TypeTable::LL), true, false, true));// 3 - false
	ruleConstant.push_back(CLL1RowElement({ stringToken }, false, CTransition(7, &ruleConstant, CTransition::TypeTable::LL), false, true, false));
	ruleConstant.push_back(CLL1RowElement({ stringToken }, true, notLLTransition, true, true, false));


	auto walker = HybridWalker(LRTable1, LLTable1, HybridWalker::State::LLCheck);
	std::vector<SToken> inputSeq = { startBlockToken, intToken, plusToken, intToken, endBlockToken };//

	auto constantRuleWalker = HybridWalker(LRNull, ruleConstant, HybridWalker::State::LLCheck);
	std::vector<SToken> constantSeq = { intToken };//

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

