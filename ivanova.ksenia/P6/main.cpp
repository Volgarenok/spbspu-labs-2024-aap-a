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
  std::cout << std::boolalpha << ivanova::rightString(string) << "\n";
  delete[] string;
  return 0;
}
