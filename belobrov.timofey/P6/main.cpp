#include <iostream>
#include "inputString.hpp"
#include "checkString.hpp"

int main()
{
  char* string = belobrov::inputString(std::cin);
  if (!string) {
    std::cerr << "Memory allocation error!\n";
    return 1;
  }
  if (string[0] == '\0') {
    free(string);
    std::cerr << "Line is empty!\n";
    return 1;
  }
  std::cout << std::boolalpha << belobrov::validateFloat(string) << "\n";
  free(string);
  return 0;
}
