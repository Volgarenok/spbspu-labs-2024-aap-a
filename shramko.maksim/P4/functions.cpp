#include "functions.hpp"
#include <cstdlib>
#include <iostream>

char* shramko::createBiggerStrMemory(size_t memory, char* str)
{
	char* new_str = reinterpret_cast< char* >(malloc((memory + 1) * sizeof(char)));

	for (size_t i = 0; str[i] != '\0'; i++)
	{
		new_str[i] = str[i];
	}
	free(str);
	new_str[memory] = '\0';
	return new_str;
}

size_t shramko::countConsecutiveIdenticalSymbols(char* str)
{
	size_t result = 0;

	if (str == nullptr)
	{
		return 0;
	}

	for (size_t i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == str[i + 1])
		{
			result++;
		}
	}
	return result;
}
