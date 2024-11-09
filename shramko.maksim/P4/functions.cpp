#include "functions.hpp"
#include <cstdlib>
#include <iostream>

char* shramko::createBiggerStrMemory(size_t memory, char* str)
{
	char* new_str = reinterpret_cast< char* >(malloc((memory + 1) * sizeof(char)));
	if (new_str == nullptr)
	{
		std::cerr << "Creating bigger memory error!\n";
		free(str);
		free(new_str);
		return nullptr;
	}

	for (size_t i = 0; str[i] != '\n'; i++)
	{
		new_str[i] = str[i];
	}

	return new_str;
}

size_t shramko::countConsecutiveIdenticalSymbols(char* str)
{
	size_t result = 0;
	for (size_t i = 0; str[i] != '\n'; i++)
	{
		if (str[i] == str[i + 1])
		{
			result++;
		}
	}
	return result;
}
