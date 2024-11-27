#include <iostream>
#include "recursion.hpp"

int main()
{
  char str1[] = "(1488*a)*b";
  std::cout << (bool)evstyunichev::IsExpressionCorrect(str1) << '\n';
  return 0;
}