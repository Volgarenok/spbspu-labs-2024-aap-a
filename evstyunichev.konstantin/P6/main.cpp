#include <iostream>
#include <cstrings.hpp>
#include "recursion.hpp"

int main()
{
  char *str1 = evstyunichev::get_string(std::cin);
  std::cout << std::boolalpha << (bool)evstyunichev::IsExpressionCorrect(str1) << '\n';
  return 0;
}