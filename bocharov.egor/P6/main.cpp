#include <iostream>
#include <getline.h>
#include "isexpression.h"
int main()
{
  char symbol = '\0';
  char * string = bocharov::getline(std::cin, symbol);
  if (string == nullptr)
  {
    std::cerr << "Error: not enough memory\n";
    return 1;
  }
  if (string[0] == '\0')
  {
    delete[] string;
    std::cerr << "Error: input error - empty str\n";
    return 1;
  }
  std::cout << std::boolalpha;
  std::cout << bocharov::isExpression(string) << "\n";
  delete[] string;
  return 0;
}
