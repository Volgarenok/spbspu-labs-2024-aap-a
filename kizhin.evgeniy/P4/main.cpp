#include <iostream>
#include <string_utils.hpp>
#include "remove_latin_letters.hpp"

int main()
{
  char* inputString = kizhin::readString(std::cin);
  if (!inputString || inputString[0] == '\0') {
    std::cerr << "Failed to read the string\n";
    free(inputString);
    return 1;
  }
  kizhin::removeLatinLetters(inputString, inputString);
  std::cout << inputString << '\n';
  free(inputString);
}

