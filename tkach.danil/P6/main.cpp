#include <iostream>
#include <stringinput.hpp>
#include "isexpression.h"

int main()
{
  size_t capacity = 2;
  char* str = tkach::inputStr(std::cin, capacity);
  if (str == nullptr)
  {
    std::cerr << "Error: not enough memory\n";
    return 1;
  }
  if (str[0] == '\0')
  {
    free(str);
    std::cerr << "Error: input error - empty str\n";
    return 1;
  }
  std::cout << std::boolalpha;
  std::cout << tkach::isExpression(str) << "\n";
  free(str);
  return 0;
}
