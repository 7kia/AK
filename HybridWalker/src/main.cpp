// LRTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HybridWalker.h"

int main()
{
	LRTable LRTable1 =
	{
		{ CLRRowElement("S", -1, true), CLRRowElement("E", 1, false), CLRRowElement("T", 2, false), CLRRowElement("F", 3, false), CLRRowElement("+", -1, true), CLRRowElement("*", -1, true), CLRRowElement("-", 4, true), CLRRowElement("(", 5, true), CLRRowElement(")", -1, true), CLRRowElement("id", 6, true), CLRRowElement("num", 7, true), CLRRowElement("", -1, false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", -1, false), CLRRowElement("F", -1, false), CLRRowElement("+", 8, true), CLRRowElement("*", -1, true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1, true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("S", 1), false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", -1, false), CLRRowElement("F", -1, false), CLRRowElement("+", -1, Rule("E", 1), true), CLRRowElement("*", 9, true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1, Rule("E", 1), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("E", 1), false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", -1, false), CLRRowElement("F", -1, false), CLRRowElement("+", -1, Rule("T", 1), true), CLRRowElement("*", -1, Rule("T", 1), true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1, Rule("T", 1), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("T", 1), false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", -1, false), CLRRowElement("F", 12, false), CLRRowElement("+", -1, true), CLRRowElement("*", -1, true), CLRRowElement("-", -1, true), CLRRowElement("(", 5, true) , CLRRowElement(")", -1, true), CLRRowElement("id", 6, true), CLRRowElement("num", 7, true), CLRRowElement("", -1, false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", 11, false), CLRRowElement("T", 2, false), CLRRowElement("F", 3, false), CLRRowElement("+", -1, true), CLRRowElement("*", -1, true), CLRRowElement("-", 4, true), CLRRowElement("(", 5, true) , CLRRowElement(")", -1, true), CLRRowElement("id", 6, true), CLRRowElement("num", 7, true), CLRRowElement("", -1, false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", -1, false), CLRRowElement("F", -1, false), CLRRowElement("+", -1, Rule("F", 1), true), CLRRowElement("*", -1, Rule("F", 1), true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1, Rule("F", 1), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("F", 1), false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", -1, false), CLRRowElement("F", -1, false), CLRRowElement("+", -1, Rule("F", 1), true), CLRRowElement("*", -1, Rule("F", 1), true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1, Rule("F", 1), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("F", 1), false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", 10, false), CLRRowElement("F", 3, false), CLRRowElement("+", -1, true), CLRRowElement("*", -1, true), CLRRowElement("-", 4, true), CLRRowElement("(", 5, true) , CLRRowElement(")", -1, true), CLRRowElement("id", 6, true), CLRRowElement("num", 7, true), CLRRowElement("", -1, false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", -1, false), CLRRowElement("F", 14, false), CLRRowElement("+", -1, true), CLRRowElement("*", -1, true), CLRRowElement("-", 4, true), CLRRowElement("(", 5, true) , CLRRowElement(")", -1, true), CLRRowElement("id", 6, true), CLRRowElement("num", 7, true), CLRRowElement("", -1, false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", -1, false), CLRRowElement("F", -1, false), CLRRowElement("+", -1, Rule("E", 3), true), CLRRowElement("*", 9, true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1, Rule("E", 3), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("E", 3), false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", -1, false), CLRRowElement("F", -1, false), CLRRowElement("+", 8, true), CLRRowElement("*", -1, true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", 13, true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", -1, false), CLRRowElement("F", -1, false), CLRRowElement("+", -1, Rule("F",2), true), CLRRowElement("*", -1, Rule("F",2),true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1,Rule("F",2), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("F",2),false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", -1, false), CLRRowElement("F", -1, false), CLRRowElement("+", -1, Rule("F",3), true), CLRRowElement("*", -1, Rule("F",3),true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1,Rule("F",3), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("F",3),false) },
		{ CLRRowElement("S", -1, false), CLRRowElement("E", -1, false), CLRRowElement("T", -1, false), CLRRowElement("F", -1, false), CLRRowElement("+", -1, Rule("T",3), true), CLRRowElement("*", -1, Rule("T",3),true), CLRRowElement("-", -1, true), CLRRowElement("(", -1, true) , CLRRowElement(")", -1,Rule("T",3), true), CLRRowElement("id", -1, true), CLRRowElement("num", -1, true), CLRRowElement("", -1, Rule("T",3),false) },
	};
	LLTable LLTable1 =
	{
		CLL1RowElement({ "prog" }, false, CTransition(1, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "prog" }, true, CTransition(2, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "id" }, true, CTransition(3, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "var" }, false, CTransition(7, &LLTable1, CTransition::TypeTable::LL), true, true, false),
		CLL1RowElement({ "begin" }, true, CTransition(5, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "st" }, false, CTransition(18, &LLTable1, CTransition::TypeTable::LL), true, true, false),
		CLL1RowElement({ "end" }, false, CTransition(-1, &LLTable1, CTransition::TypeTable::LL), false, true, true),
		CLL1RowElement({ "var" }, false, CTransition(8, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "var" }, true, CTransition(9, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "id" }, false, CTransition(10, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "id" }, false, CTransition(11, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "id" }, true, CTransition(12, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "begin", "," }, false, CTransition(13, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "," }, false, CTransition(15, &LLTable1, CTransition::TypeTable::LL), false, false, false),
		CLL1RowElement({ "begin" }, false, CTransition(17, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "," }, true, CTransition(16, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "id" }, false, CTransition(10, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "begin" }, false, CTransition(-1, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "st" }, false, CTransition(19, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "st" }, true, CTransition(20, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "st", "end" }, false, CTransition(21, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "st" }, false, CTransition(23, &LLTable1, CTransition::TypeTable::LL), false, false, false),
		CLL1RowElement({ "end" }, false, CTransition(24, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "st", "end" }, false, CTransition(18, &LLTable1, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "end" }, false, CTransition(-1, &LLTable1, CTransition::TypeTable::LL), false, true, false)
	};

	std::vector<std::string> inputSeq = {"-", "(",  "id", "+", "id", ")"};

	auto walker = HybridWalker(LRTable1, LLTable1, HybridWalker::State::LRCheck);
	try
	{
		if (walker.CheckInputSequence(inputSeq))
		{
			std::cout << "LR Success!" << std::endl;
		}
		else
		{
			std::cout << "LR Error!" << std::endl;
		}
	}
	catch (std::runtime_error & err)
	{
		std::cout << err.what();
	}

	// LL test
	std::cout << std::endl;

	std::vector<std::string> str2{ "prog", "id", "var", "id", ",", "id",  ",",  "id", "begin", "st", "st", "end" };

	try
	{
		walker.SetState(HybridWalker::State::LLCheck);
		if (walker.CheckInputSequence(str2))
		{
			std::cout << "LL Success!" << std::endl;
		}
		else
		{
			std::cout << "LL Error!" << std::endl;
		}
	}
	catch (std::runtime_error & err)
	{
		std::cout << err.what();
	}
	

    return 0;
}

