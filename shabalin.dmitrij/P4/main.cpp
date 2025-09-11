#include <iostream>
#include <inputOfString.hpp>
#include "removeVowels.h"

int main()
{
  constexpr char end = '\n';
  char *inputString = nullptr;
  inputString = shabalin::inputOfString(std::cin, end);
  if (inputString == nullptr)
  {
    std::cerr << "Input Error\n";
    return 1;
  }
  if (inputString[0] == '\0')
  {
    free(inputString);
    std::cerr << "Error: Empty input\n";
    return 1;
  }
  shabalin::removeVowels(inputString);
  std::cout << inputString << "\n";

  free(inputString);
  return 0;
}
