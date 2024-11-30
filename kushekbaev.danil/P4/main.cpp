#include <cstring>
#include <iostream>
#include <read_input_array.hpp>
#include "has_common_chars.hpp"

int main()
{
  size_t max = 10;
  size_t size = 0;
  char stop = '\0';

  const char * str1 = kushekbaev::readInputArray(std::cin, stop, size, max);

  const char * str2 = "string literal";

  if (size == 0)
  {
    std::cerr << "Failed input" << "\n";
    delete[] str1;
    delete[] str2;
    return 1;
  }

  std::cout << kushekbaev::hasCommonChars(str1, str2, strlen(str1), strlen(str2)) << "\n";

  delete[] str1;
  delete[] str2;
  return 0;
}
