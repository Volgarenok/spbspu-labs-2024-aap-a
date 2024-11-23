#include <iostream>
#include <ios>
#include <cstddef>
#include <fstream>
#include "modifyString.hpp"

int main()
{
  char* str = shramko::inputStr(std::cin);
  if (str == nullptr)
  {
    std::cerr << "Main error!\n";
    return 1;
  }

  if (str[0] == '\0')
  {
    free(str);
    std::cerr << "Empty string\n";
    return 1;
  }

  std::cout << shramko::countConsecutiveIdenticalSymbols(str) << '\n';
  free(str);
}
