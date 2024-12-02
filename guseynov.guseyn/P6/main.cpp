#include <iostream>
#include <workWithString.hpp>
#include "is_double.hpp"

int main()
{
  char * str = guseynov::getLine(std::cin);
  if (str == nullptr)
  {
    return 1;
  }
  std::cout << std::boolalpha << guseynov::isDouble(str) << "\n";
  free(str);
  return 0;
}
