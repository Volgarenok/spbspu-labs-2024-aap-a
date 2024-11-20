#include <ios>
#include <iostream>
#include "isexpression.hpp"

int main()
{
  const char * str = "10x";
  const char * yastr = "2a";
  std::cout << std::boolalpha << brevnov::isExpreession(str) << "\n";
  std::cout << std::boolalpha << brevnov::isExpreession(yastr) << "\n";
}
