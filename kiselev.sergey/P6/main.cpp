#include <inputString.h>
#include <ios>
#include <iostream>
#include "isExpression.h"
int main()
{
  char* string = kiselev::inputString();
  if (!string || string[0] == '\0')
  {
    std::cerr << "Failed string reading\n";
    return 1;
  }
  std::cout << std::boolalpha << kiselev::isExpression(string) << "\n";
  return 0;
}
