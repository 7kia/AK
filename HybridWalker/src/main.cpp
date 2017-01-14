// LRTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HybridWalker.h"

int main()
{
	LRTable LRTable1;
	LLTable LLTable1;

	{
		/*
				{ CLRRowElement("S", -1, true), CLRRowElement("E", 1, false)); CLRRowElement("T", 2, false)); CLRRowElement("F", 3, false)); CLRRowElement("+", -1, true), CLRRowElement("*", -1, true), CLRRowElement("-", 4, true), CLRRowElement("(", 5, true), CLRRowElement(")", -1, true), CLRRowElement("id", 6, true), CLRRowElement("num", 7, true), CLRRowElement("", -1, false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", -1, false)); CLRRowElement("F", -1, false)); CLRRowElement("+", 8, true), CLRRowElement("*", -1, true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1, true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("S", 1), false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", -1, false)); CLRRowElement("F", -1, false)); CLRRowElement("+", -1, Rule("E", 1), true), CLRRowElement("*", 9, true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1, Rule("E", 1), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("E", 1), false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", -1, false)); CLRRowElement("F", -1, false)); CLRRowElement("+", -1, Rule("T", 1), true), CLRRowElement("*", -1, Rule("T", 1), true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1, Rule("T", 1), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("T", 1), false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", -1, false)); CLRRowElement("F", 12, false)); CLRRowElement("+", -1, true), CLRRowElement("*", -1, true), CLRRowElement("-", -1, true), CLRRowElement("(", 5, true) , CLRRowElement(")", -1, true), CLRRowElement("id", 6, true), CLRRowElement("num", 7, true), CLRRowElement("", -1, false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", 11, false)); CLRRowElement("T", 2, false)); CLRRowElement("F", 3, false)); CLRRowElement("+", -1, true), CLRRowElement("*", -1, true), CLRRowElement("-", 4, true), CLRRowElement("(", 5, true) , CLRRowElement(")", -1, true), CLRRowElement("id", 6, true), CLRRowElement("num", 7, true), CLRRowElement("", -1, false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", -1, false)); CLRRowElement("F", -1, false)); CLRRowElement("+", -1, Rule("F", 1), true), CLRRowElement("*", -1, Rule("F", 1), true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1, Rule("F", 1), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("F", 1), false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", -1, false)); CLRRowElement("F", -1, false)); CLRRowElement("+", -1, Rule("F", 1), true), CLRRowElement("*", -1, Rule("F", 1), true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1, Rule("F", 1), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("F", 1), false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", 10, false)); CLRRowElement("F", 3, false)); CLRRowElement("+", -1, true), CLRRowElement("*", -1, true), CLRRowElement("-", 4, true), CLRRowElement("(", 5, true) , CLRRowElement(")", -1, true), CLRRowElement("id", 6, true), CLRRowElement("num", 7, true), CLRRowElement("", -1, false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", -1, false)); CLRRowElement("F", 14, false)); CLRRowElement("+", -1, true), CLRRowElement("*", -1, true), CLRRowElement("-", 4, true), CLRRowElement("(", 5, true) , CLRRowElement(")", -1, true), CLRRowElement("id", 6, true), CLRRowElement("num", 7, true), CLRRowElement("", -1, false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", -1, false)); CLRRowElement("F", -1, false)); CLRRowElement("+", -1, Rule("E", 3), true), CLRRowElement("*", 9, true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1, Rule("E", 3), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("E", 3), false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", -1, false)); CLRRowElement("F", -1, false)); CLRRowElement("+", 8, true), CLRRowElement("*", -1, true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", 13, true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", -1, false)); CLRRowElement("F", -1, false)); CLRRowElement("+", -1, Rule("F",2), true), CLRRowElement("*", -1, Rule("F",2),true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1,Rule("F",2), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("F",2),false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", -1, false)); CLRRowElement("F", -1, false)); CLRRowElement("+", -1, Rule("F",3), true), CLRRowElement("*", -1, Rule("F",3),true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1,Rule("F",3), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("F",3),false) },
		{ CLRRowElement("S", -1, false)); CLRRowElement("E", -1, false)); CLRRowElement("T", -1, false)); CLRRowElement("F", -1, false)); CLRRowElement("+", -1, Rule("T",3), true), CLRRowElement("*", -1, Rule("T",3),true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1,Rule("T",3), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("T",3),false) },

		*/
		
	};
	CTransition notLLTransition(-1, nullptr, CTransition::TypeTable::LL);
	CTransition notLRTransition(-1, nullptr, CTransition::TypeTable::LR);

	LRTable1.push_back({ CLRRowElement("prog", notLRTransition, false), CLRRowElement("exp", notLRTransition, true),  CLRRowElement("int", CTransition(1, &LRTable1, CTransition::TypeTable::LR), true) });
	LRTable1.push_back({ CLRRowElement("prog", notLRTransition, false), CLRRowElement("exp", notLRTransition, false), CLRRowElement("int", notLRTransition, false), CLRRowElement("+", CTransition(2, &LRTable1, CTransition::TypeTable::LR), true), CLRRowElement("-", CTransition(2, &LRTable1, CTransition::TypeTable::LR), true), CLRRowElement("", notLRTransition, Rule("exp", 1), true) });
	LRTable1.push_back({ CLRRowElement("prog", notLRTransition, false), CLRRowElement("exp", notLRTransition, false), CLRRowElement("int", CTransition(3, &LRTable1, CTransition::TypeTable::LR), true) });
	LRTable1.push_back({ CLRRowElement("prog", notLRTransition, false), CLRRowElement("exp", notLRTransition, false), CLRRowElement("int", CTransition(-1, &LRTable1, CTransition::TypeTable::LR), Rule("exp", 3), false), CLRRowElement("end", CTransition(-1, &LRTable1, CTransition::TypeTable::LR), Rule("exp", 3), false) });



	LLTable1.push_back(CLL1RowElement({ "prog" }, false, CTransition(1, &LLTable1, CTransition::TypeTable::LL), false, true, false));
	LLTable1.push_back(CLL1RowElement({ "prog" }, true, CTransition(0, &LRTable1, CTransition::TypeTable::LR), true, true, false));
	LLTable1.push_back(CLL1RowElement({ "exp" }, false, CTransition(3, &LLTable1, CTransition::TypeTable::LL), false, true, false));
	LLTable1.push_back(CLL1RowElement({ "exp" }, true, CTransition(4, &LLTable1, CTransition::TypeTable::LL), true, true, false));
	LLTable1.push_back(CLL1RowElement({ "end" }, false, CTransition(5, &LLTable1, CTransition::TypeTable::LL), false, true, false));
	LLTable1.push_back(CLL1RowElement({ "end" }, true, notLLTransition, true, true, true));


	std::vector<std::string> inputSeq = {"prog", "int", "+", "int", "end"};

	auto walker = HybridWalker(LRTable1, LLTable1, HybridWalker::State::LLCheck);
	try
	{
		if (walker.CheckInputSequence(inputSeq))
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

