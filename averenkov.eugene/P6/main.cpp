#include <iostream>
#include <dynamicinput.h>
#include "isReal.h"

int main()
{
  char* input = averenkov::stringInput(std::cin);
  if (input[0] == '\0')
  {
    std::cerr << "Empty string";
    free(input);
    return 1;
  }
  if (input == nullptr)
  {
    std::cerr << "Memory error\n";
    return 1;
  }
  std::cout << std::boolalpha << averenkov::isReal(input) << "\n";
  free(input);
  return 0;
}
