#include <iostream>
#include <ios>
#include <cstddef>
#include <fstream>
#include "functions.hpp"

int main()
{
  size_t memory = 4;
  char* str = reinterpret_cast< char* >(malloc((memory + 1) * sizeof(char)));
  if (str == nullptr)
  {
    std::cerr << "Malloc error!\n";
    free(str);
    return 1;
  }
  str[memory] = '\0';
  size_t current_size = 0;
  char c = '\0';

  std::noskipws(std::cin);
  while ((std::cin >> c) && (c != '\n'))
  {
    if (current_size == memory)
    {
      constexpr size_t multiplier = 2;
      memory *= multiplier;
      char* new_str = shramko::createBiggerStrMemory(memory, str);
      if (new_str == nullptr)
      {
        std::cerr << "Memory error!\n";
	free(str);
	free(new_str);
	return 1;
      }
      str = new_str;
    }
    str[current_size++] = c;
  }
  std::skipws(std::cin);

  if (current_size == 0)
  {
    std::cerr << "Nothing in string\n";
    free(str);
    return 1;
  }

  std::cout << shramko::countConsecutiveIdenticalSymbols(str) << '\n';
  free(str);
}
