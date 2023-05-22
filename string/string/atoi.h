#pragma once

namespace ObStr
{
	/*
	*	atoi
	*	1. White-space characters at the beginning of the string are ignored.
	*	2. Signs (+, -) can come at most one.
	*	3. If it starts reading a number once, it reads just before another letter comes.
	*/
	template<typename T>
	T atoi_implement(const char* str)
	{
		// Ignore white-space characters
		//while (std::isspace(static_cast<unsigned char>(*str)))
		while (('\t' <= *str && *str <= '\r') || (*str == ' '))
		{
			++str;
		}

		// Check sign
		bool negative = false;
		if (*str == '+')
		{
			++str;
		}
		else if (*str == '-')
		{
			++str;
			negative = true;
		}

		T result = 0;
		//for (; std::isdigit(static_cast<unsigned char>(*str)); ++str)
		for (; '0' <= *str && *str <= '9'; ++str)
		{
			int digit = *str - '0';
			result *= 10;
			result -= digit;	// calculate in negatives to support INT_MIN, LONG_MIN, ...
		}

		return negative ? result : -result;
	}

	int atoi(const char* str)
	{
		return atoi_implement<int>(str);
	}

	long atol(const char* str)
	{
		return atoi_implement<long>(str);
	}

	long long atoll(const char* str)
	{
		return atoi_implement<long long>(str);
	}
}