#include <iostream>
#include <istream>
#include <inputStr.hpp>
#include "expressions.hpp"

int main()
{
  size_t len = 0;
  const char* str = inputStr(std::cin, len);
  if (!str || len == 0) {
    std::cerr << "Wrong input!" << "\n";
    return 1;
  }
  std::cout << std::boolalpha << gavrilova::is_expression(str) << "\n";
}
