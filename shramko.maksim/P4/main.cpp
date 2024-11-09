#include <iostream>
#include <ios>
#include <cstddef>
#include <fstream>

int main()
{
	constexpr size_t MEMORY = 10;
	char* str = reinterpret_cast< char* >(malloc((MEMORY + 1) * sizeof(char)));
	if (str == nullptr)
	{
		std::cerr << "Malloc error!\n";
		free(str);
		return 1;
	}

	size_t size = 0;
	char c = '\n';

	std::noskipsw(std::cin);
	while ((std::cin >> c) && (c != '\n'))
	{
		str[size++] = c;
	}
	std::skipsw(std::cin);
}
