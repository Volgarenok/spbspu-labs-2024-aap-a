#include <iostream>
#include <cstddef>
#include "../../asafov.andrew/common/inputString.hpp"
#include "isExpression.hpp"

int main()
{
  char* str = asafov::inputString();
  size_t len = 0;
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    len++;
  }
  std::cout << asafov::isExpression(str, 0, len) << std::endl;
}
