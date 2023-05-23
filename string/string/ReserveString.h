#pragma once

#include <iostream>
#include <cassert>

namespace ObStr
{
	/*
	*	ReserveString
	*	1. destSize must be larger than sourceSize.
	*	2. Copy source data to dest
	*/
	void ReserveString(char* dest, const size_t destSize, const char* source, const size_t sourceSize)
	{
		// Check size
		if (_DEBUG)
		{
			assert(destSize > sourceSize);
		}
		else if (destSize <= sourceSize)
		{
			std::cout << "Destination size is smaller than source size!" << std::endl;
			return;
		}

		char* newString = dest;
		const char* oldString = source;

		// Copy data
		for (size_t stringIndex = 0; stringIndex < sourceSize; ++stringIndex)
		{
			*newString++ = *oldString++;
		}
		*newString = '\0';

		dest = newString;
	}
}