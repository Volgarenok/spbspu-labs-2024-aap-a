#include <iostream>
#include <dynamicinput.h>
#include "recfunc.h"
int main() {
  char* input = nullptr;
  input = averenkov::stringInput(std::cin, input);
  if (input == nullptr)
  {
    std::cerr << "Memory error\n";
    return 1;
  }
  const char* ptr = input;
  if (averenkov::hasExpression(ptr) && *ptr == '\0') {
    std::cout << "yes\n";
  }
  else
  {
    std::cout << "no\n";
  }
  free(input);
  return 0;
}
