#include <iostream>
#include <dynamicinput.h>
#include "recfunc.h"
int main() {
  char* input = nullptr;
  input = averenkov::stringInput(std::cin, input);
  if(input[0] == '\0')
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
  const char* ptr = input;
  if (averenkov::hasExpression(ptr) && *ptr == '\0') {
    std::cout << "true\n";
  }
  else
  {
    std::cout << "false\n";
  }
  free(input);
  return 0;
}
