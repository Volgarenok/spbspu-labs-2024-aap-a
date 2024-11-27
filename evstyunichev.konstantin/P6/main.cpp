#include <iostream>
#include "recursion.hpp"

int main()
{
  char str1[] = "21*25**a";
  std::cout << (bool)evstyunichev::IsTermCorrect(str1) << '\n';
  return 0;
}