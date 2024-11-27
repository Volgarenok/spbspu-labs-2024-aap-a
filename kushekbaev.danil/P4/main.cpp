#include <iostream>
#include <arrays_input.hpp>
#include "has_common_chars.hpp"

int main()
{
  size_t max = 10;
  size_t size = 0;

  char * str1 = kushekbaev::readInputArray(std::cin, \0, size1, max);

  const char * str2 = "string literal" << "\n";

  if (size == 0)
  {
    std::cerr << "Failed input" << "\n";
    delete[] str1;
    delete[] str2;
    return 1;
  }

  std::cout << kushekbaev::hasCommonChars(str1, size, str2) << "\n";

  delete[] str1;
  delete[] str2;
  return 0;
}
