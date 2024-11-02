#include "cmd_parameters.h"
#include <cstdlib>
#include <stdexcept>
int alymova::check_num(char* argv1)
{
	constexpr int ascii_0 = 48;
	constexpr int ascii_9 = 57;
	for (size_t i = 0; argv1[i] != '\0'; i++)
	{
		if (ascii_0 > int(argv1[i]) || int(argv1[i]) > ascii_9)
		{
			throw std::logic_error("First parameter is not a number");
		}
	}
	int num = atoi(argv1);
	if (num < 1 || num > 2)
	{
		throw std::logic_error("First parameter is out of range");
	}
	return num;
}
