#include<iostream>
#include<inputString.hpp>
#include "isExpression.hpp"
int main()
{
  char * str = nullptr;
  try
  {
    str = sharifullina::inputStringRecursive(std::cin, '\n');
  }
  catch (const std::exception& e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  if (str[0] == '\0')
  {
    delete[] str;
    std::cerr << "Empty input\n";
    return 1;
  }
  std::cout << std::boolalpha;
  std::cout << sharifullina::isExpression(str) << "\n";
  delete[] str;
}
