// LRTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HybridWalker.h"
#include "LL1Walker.h"// ToDO : delete

int main()
{
	LRTable table =
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

	std::vector<std::string> inputSeq = {"-", "(",  "id", "+", "id", ")"};

	auto walker = HybridWalker(inputSeq, table);
	try
	{
		if (walker.CheckInputSequence())
		{
			std::cout << "Success!" << std::endl;
		}
		else
		{
			std::cout << "Error!" << std::endl;
		}
	}
	catch (std::runtime_error & err)
	{
		std::cout << err.what();
	}

	// LL test
	std::cout << std::endl;

	LL1Table table2 =
	{
		CLL1RowElement({ "prog" }, false, CTransition(1, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "prog" }, true, CTransition(2, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "id" }, true, CTransition(3, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "var" }, false, CTransition(7, &table2, CTransition::TypeTable::LL), true, true, false),
		CLL1RowElement({ "begin" }, true, CTransition(5, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "st" }, false, CTransition(18, &table2, CTransition::TypeTable::LL), true, true, false),
		CLL1RowElement({ "end" }, false, CTransition(-1, &table2, CTransition::TypeTable::LL), false, true, true),
		CLL1RowElement({ "var" }, false, CTransition(8, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "var" }, true, CTransition(9, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "id" }, false, CTransition(10, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "id" }, false, CTransition(11, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "id" }, true, CTransition(12, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "begin", "," }, false, CTransition(13, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "," }, false, CTransition(15, &table2, CTransition::TypeTable::LL), false, false, false),
		CLL1RowElement({ "begin" }, false, CTransition(17, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "," }, true, CTransition(16, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "id" }, false, CTransition(10, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "begin" }, false, CTransition(-1, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "st" }, false, CTransition(19, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "st" }, true, CTransition(20, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "st", "end" }, false, CTransition(21, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "st" }, false, CTransition(23, &table2, CTransition::TypeTable::LL), false, false, false),
		CLL1RowElement({ "end" }, false, CTransition(24, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "st", "end" }, false, CTransition(18, &table2, CTransition::TypeTable::LL), false, true, false),
		CLL1RowElement({ "end" }, false, CTransition(-1, &table2, CTransition::TypeTable::LL), false, true, false)
	};

	std::vector<std::string> str2{ "prog", "id", "var", "id", ",", "id",  ",",  "id", "begin", "st", "st", "end" };

	LL1Walker walker2(table2);
	try
	{
		if (walker2.CheckInputSequence(str2))
		{
			std::cout << "Success!";
		}
	}
	catch (std::runtime_error & err)
	{
		std::cout << err.what();
	}
	

    return 0;
}

