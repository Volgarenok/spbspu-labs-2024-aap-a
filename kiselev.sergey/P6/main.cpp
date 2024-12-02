#include <iostream>
#include <inputString.h>
#include "isExpression.h"
int main()
{
  char* string = kiselev::inputString(std::cin, '\n');
  if (!string || string[0] == '\0')
  {
    std::cerr << "Failed string reading\n";
    free(string);
    return 1;
  }
  std::cout << std::boolalpha << kiselev::isExpression(string) << "\n";
  free(string);
  return 0;
}
