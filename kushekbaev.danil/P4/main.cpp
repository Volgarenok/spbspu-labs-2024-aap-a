#include <cstring>
#include <iostream>
#include <read_input_array.hpp>
#include "has_common_chars.hpp"

int main()
{
  const char * str1 = kushekbaev::readInputArray(std::cin);

  const char * str2 = "string literal";

  if (str1 == nullptr)
  {
    std::cerr << "Failed input" << "\n";
    delete[] str1;
    return 1;
  }

  std::cout << kushekbaev::hasCommonChars(str1, str2) << "\n";

  delete[] str1;
  return 0;
}
