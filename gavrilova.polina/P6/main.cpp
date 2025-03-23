#include <iostream>
#include <istream>
#include <inputStr.hpp>
#include "expressions.hpp"

int main()
{
  size_t len = 0;
  size_t nSpaces = 0;
  const char* str = gavrilova::inputStr(std::cin, len, nSpaces);
  if (!str || str[0] == '\0') {
    std::cerr << "Wrong input!" << "\n";
    delete[] str;
    return 1;
  }
  std::cout << std::boolalpha << gavrilova::is_expression(str) << "\n";
  delete[] str;
}
