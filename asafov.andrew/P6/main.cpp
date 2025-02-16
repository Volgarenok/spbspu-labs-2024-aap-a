#include <iostream>
#include <cstddef>
#include <inputString.hpp>
#include "isExpression.hpp"

int main()
{
  char* str = asafov::inputString(std::cin);
  size_t len = 0;
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    len++;
  }
  if (len == 0)
  {
    std::cerr << "empty string" << '\n';
    delete[] str;
    return 1;
  }
  std::cout << std::boolalpha << asafov::isExpression(str, 0, len - 1) << '\n';
  delete[] str;
  return 0;
}
