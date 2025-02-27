#include <iostream>
#include "inputString.hpp"
#include "replaceChars.hpp"

int main()
{
  char* line = belobrov::inputString(std::cin);
  if (line == nullptr) {
    std::cerr << "Memory allocation error!\n";
    return 1;
  }

  if (line[0] == '\0') {
    std::cerr << "Line is empty!\n";
    free(line);
    return 1;
  }

  constexpr char oldChar = 'c';
  constexpr char newChar = 'b';
  std::cout << belobrov::replaceChars(line, oldChar, newChar);
  std::cout << "\n";
  free(line);
  return 0;
}
