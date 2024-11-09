#include <cstring>
#include <iostream>
#include "string_utils.hpp"

int main()
{
  char* inputString = nullptr;
  inputString = kizhin::readString(std::cin);
  if (!inputString || !std::cin.good()) {
    std::cerr << "Failed to read the string\n";
    return 1;
  }
  char* transformedString
      = static_cast<char*>(malloc(sizeof(char) * std::strlen(inputString)));
  if (!transformedString) {
    free(inputString);
    std::cerr << "Failed to allocate memory\n";
    return 1;
  }
  kizhin::removeLatinLetters(transformedString, inputString);
  std::cout << transformedString << '\n';
  free(inputString);
  free(transformedString);
}

