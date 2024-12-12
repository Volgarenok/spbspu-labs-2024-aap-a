#include <iostream>
#include <dynamicinput.h>
#include "parseexpr.h"

int main()
{
  const char* input = averenkov::stringInput(std::cin);
  if (input[0] == '\0')
  {
    std::cerr << "Empty string";
    return 1;
  }
  if (input == nullptr)
  {
    std::cerr << "Memory error\n";
    return 1;
  }
  std::cout << std::boolalpha << averenkov::isReal(input) << "\n";
  return 0;
}
