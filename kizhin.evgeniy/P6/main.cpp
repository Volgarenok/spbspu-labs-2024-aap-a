#include <iostream>
#include <string_utils.hpp>
#include "is_expression.hpp"

int main()
{
  char* inputString = kizhin::readString(std::cin);
  if (!inputString || *inputString == '\0') {
    free(inputString);
    std::cerr << "Failed to input string\n";
    return 1;
  }
  std::cout << std::boolalpha << kizhin::isExpression(inputString) << '\n';
  free(inputString);
}
