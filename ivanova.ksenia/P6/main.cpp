#include <iostream>
#include <inputString.hpp>
#include "recursiveStringCheck.h"

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
  std::cout << std::boolalpha << ivanova::rightString(string) << "\n";
  ivanova::twoFrequentSymbol(string, dest);
  std::cout << dest << "\n";
  delete[] string;
  return 0;
}
