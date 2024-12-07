#include <iostream>
#include <getLine.hpp>
#include "recursionString.hpp"
int main()
{
  size_t capacity = 10;
  char* str = maslovskiy::getLine(std::cin, capacity);
  if (!str)
  {
    std::cerr << "ERROR: impossible to getLine\n";
    return 1;
  }
  if (*str == '\0')
  {
    free(str);
    std::cerr << "ERROR: an empty input\n";
    return 2;
  }
  std::cout << std::boolalpha << maslovskiy::isDouble(str) << "\n";
  free(str);
  return 0;
}
