#include <iostream>
#include <getLine.hpp>
#include "recursionString.hpp"
int main()
{
  char *str = maslovskiy::inputString(std::cin);
  if (str == nullptr)
  {
    std::cerr << "Memory allocation failed for input string\n";
    return 1;
  }
  if (*str == '\0')
  {
    free(str);
    std::cerr << "Input string is null\n";
    return 2;
  }
  std::cout << std::boolalpha << maslovskiy::isDouble(str) << "\n";
  free(str);
}
