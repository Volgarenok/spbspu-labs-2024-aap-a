#include <iostream>
#include "string.h"

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
  ivanova::twoFrequentSymbol(string, dest);
  std::cout << ivanova::frequentSymbol(string) << '\n';
  std::cout << dest << '\n';
  delete[] string;
  return 0;
}
