// LRTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HybridWalker.h"

int main()
{
	LRTable table =
	{
		{ RowElement("S", -1, true), RowElement("E", 1, false), RowElement("T", 2, false), RowElement("F", 3, false), RowElement("+", -1, true), RowElement("*", -1, true), RowElement("-", 4, true), RowElement("(", 5, true), RowElement(")", -1, true), RowElement("id", 6, true), RowElement("num", 7, true), RowElement("", -1, false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", -1, false), RowElement("F", -1, false), RowElement("+", 8, true), RowElement("*", -1, true), RowElement("-", -1, true), RowElement("(", -1, true) , RowElement(")", -1, true), RowElement("id", -1, true), RowElement("num", -1, true), RowElement("", -1, Rule("S", 1), false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", -1, false), RowElement("F", -1, false), RowElement("+", -1, Rule("E", 1), true), RowElement("*", 9, true), RowElement("-", -1, true), RowElement("(", -1, true) , RowElement(")", -1, Rule("E", 1), true), RowElement("id", -1, true), RowElement("num", -1, true), RowElement("", -1, Rule("E", 1), false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", -1, false), RowElement("F", -1, false), RowElement("+", -1, Rule("T", 1), true), RowElement("*", -1, Rule("T", 1), true), RowElement("-", -1, true), RowElement("(", -1, true) , RowElement(")", -1, Rule("T", 1), true), RowElement("id", -1, true), RowElement("num", -1, true), RowElement("", -1, Rule("T", 1), false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", -1, false), RowElement("F", 12, false), RowElement("+", -1, true), RowElement("*", -1, true), RowElement("-", -1, true), RowElement("(", 5, true) , RowElement(")", -1, true), RowElement("id", 6, true), RowElement("num", 7, true), RowElement("", -1, false) },
		{ RowElement("S", -1, false), RowElement("E", 11, false), RowElement("T", 2, false), RowElement("F", 3, false), RowElement("+", -1, true), RowElement("*", -1, true), RowElement("-", 4, true), RowElement("(", 5, true) , RowElement(")", -1, true), RowElement("id", 6, true), RowElement("num", 7, true), RowElement("", -1, false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", -1, false), RowElement("F", -1, false), RowElement("+", -1, Rule("F", 1), true), RowElement("*", -1, Rule("F", 1), true), RowElement("-", -1, true), RowElement("(", -1, true) , RowElement(")", -1, Rule("F", 1), true), RowElement("id", -1, true), RowElement("num", -1, true), RowElement("", -1, Rule("F", 1), false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", -1, false), RowElement("F", -1, false), RowElement("+", -1, Rule("F", 1), true), RowElement("*", -1, Rule("F", 1), true), RowElement("-", -1, true), RowElement("(", -1, true) , RowElement(")", -1, Rule("F", 1), true), RowElement("id", -1, true), RowElement("num", -1, true), RowElement("", -1, Rule("F", 1), false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", 10, false), RowElement("F", 3, false), RowElement("+", -1, true), RowElement("*", -1, true), RowElement("-", 4, true), RowElement("(", 5, true) , RowElement(")", -1, true), RowElement("id", 6, true), RowElement("num", 7, true), RowElement("", -1, false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", -1, false), RowElement("F", 14, false), RowElement("+", -1, true), RowElement("*", -1, true), RowElement("-", 4, true), RowElement("(", 5, true) , RowElement(")", -1, true), RowElement("id", 6, true), RowElement("num", 7, true), RowElement("", -1, false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", -1, false), RowElement("F", -1, false), RowElement("+", -1, Rule("E", 3), true), RowElement("*", 9, true), RowElement("-", -1, true), RowElement("(", -1, true) , RowElement(")", -1, Rule("E", 3), true), RowElement("id", -1, true), RowElement("num", -1, true), RowElement("", -1, Rule("E", 3), false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", -1, false), RowElement("F", -1, false), RowElement("+", 8, true), RowElement("*", -1, true), RowElement("-", -1, true), RowElement("(", -1, true) , RowElement(")", 13, true), RowElement("id", -1, true), RowElement("num", -1, true), RowElement("", -1, false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", -1, false), RowElement("F", -1, false), RowElement("+", -1, Rule("F",2), true), RowElement("*", -1, Rule("F",2),true), RowElement("-", -1, true), RowElement("(", -1, true) , RowElement(")", -1,Rule("F",2), true), RowElement("id", -1, true), RowElement("num", -1, true), RowElement("", -1, Rule("F",2),false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", -1, false), RowElement("F", -1, false), RowElement("+", -1, Rule("F",3), true), RowElement("*", -1, Rule("F",3),true), RowElement("-", -1, true), RowElement("(", -1, true) , RowElement(")", -1,Rule("F",3), true), RowElement("id", -1, true), RowElement("num", -1, true), RowElement("", -1, Rule("F",3),false) },
		{ RowElement("S", -1, false), RowElement("E", -1, false), RowElement("T", -1, false), RowElement("F", -1, false), RowElement("+", -1, Rule("T",3), true), RowElement("*", -1, Rule("T",3),true), RowElement("-", -1, true), RowElement("(", -1, true) , RowElement(")", -1,Rule("T",3), true), RowElement("id", -1, true), RowElement("num", -1, true), RowElement("", -1, Rule("T",3),false) },
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

    return 0;
}

