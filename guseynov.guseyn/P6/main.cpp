#include <iostream>
#include <workWithString.hpp>
#include "is_double.hpp"

int main()
{
  const char * str = guseynov::getLine(std::cin);
  std::cout << std::boolalpha << guseynov::isDouble(str) << "\n";
}
