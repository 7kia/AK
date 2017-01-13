#pragma once
#include <string>
#include <boost/optional.hpp>

struct Rule
{
	Rule(const std::string & output, size_t size);
	std::string		nameRule;
	size_t			size;
};
