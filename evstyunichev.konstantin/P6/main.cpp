#include <iostream>
#include "recursion.hpp"

int main()
{
  char * str1 = "1 + 10";
  std::cout << std::boolalpha << (bool)evstyunichev::IsExpressionCorrect(str1) << '\n';
  return 0;
}