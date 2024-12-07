#include <iostream>
#include <cstrings.hpp>
#include "recursion.hpp"

int main()
{
  char *str1 = evstyunichev::get_string(std::cin);
  if (str1 && !str1[0])
  {
    std::cerr << "zero input\n";
    return 1;
  }
  std::cout << std::boolalpha << (bool)evstyunichev::IsExpressionCorrect(str1) << '\n';
  return 0;
}
