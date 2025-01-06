#include <iostream>
#include <inputString.hpp>
#include "frequentSymbols.h"

int main()
{
  char* string = ivanova::getLine(std::cin);
  if (!string || string[0] == '\0')
  {
    std::cerr << "Error in entered string" << '\n';
    delete[] string;
    return 1;
  }
  char dest[3] = {};
  ivanova::twoFrequentSymbolRec(string, dest);
  std::cout << dest[0] << '\n';
  std::cout << dest[1] << '\n';
  delete[] string;
  return 0;
}
