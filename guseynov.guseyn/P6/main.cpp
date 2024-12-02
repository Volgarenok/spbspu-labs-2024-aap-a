#include <iostream>
#include <workWithString.hpp>
#include "is_double.hpp"

int main()
{
  const char * str = guseynov::getLine(std::cin);
  if (!str)
  {
    return 1;
  }
  std::cout << std::boolalpha << guseynov::isDouble(str) << "\n";
  free(str);x
  return 0;
}
