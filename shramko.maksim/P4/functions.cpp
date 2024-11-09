#include "functions.hpp"
#include <cstdlib>

char* shramko::createBiggerStrMemory(memory, str)
{
	char* new_str = reinterpret_cast< char* >(malloc((memory + 1) * sizeof(char)));
	if (new_str == nullptr)
	{
		std::cerr << "Creating bigger memory error!\n";
		free(str);
		free(new_str);
		return 1;
	}

	for (size_t i = 0; str[i] != '\n'; i++)
	{
		new_str[i] = str[i];
	}

	return new_str;
}
