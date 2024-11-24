#include <iostream>
#include <inputString.h>
#include "identicalChar.h"
int main()
{
  char* string = kiselev::inputString(std::cin, '\n');
  if (string == nullptr || string[0] == '\0')
  {
    std::cerr << "Failed string reading\n";
    free(string);
    return 1;
  }
  const char secondString[] = "abs";
  size_t countIdentical = kiselev::identicalChar(string, secondString);
  std::cout << "Identical character: " << countIdentical << "\n";
  free(string);
  return 0;
}
