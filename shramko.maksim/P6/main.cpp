#include <iostream>
#include <inputString.hpp>
#include "isExpression.hpp"

int main()
{
  char* str = shramko::inputStr(std::cin);
  if (str == nullptr)
  {
    std::cerr << "String error!\n";
    return 1;
  }

  if (str[0] == '\0')
  {
    free(str);
    std::cerr << "String is empty!\n";
    return 1;
  }

  std::cout << std::boolalpha << shramko::is_expression(str) << '\n';
  free(str);
}
