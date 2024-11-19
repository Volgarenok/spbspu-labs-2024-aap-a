#include <iostream>

#include "workWithString.hpp"

int main()
{
  char *arr = nullptr;
  constexpr size_t numOfLetters = 26;
  constexpr char stop = '\n';
  arr = guseynov::getLine(std::cin, stop);
  if (arr == nullptr)
  {
    return 1;
  }
  constexpr char uniqueChars[numOfLetters] = {'a', 'b', 'c', 'd','e', 'f', 'g', 'h', 'i',
  'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r',
  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  std::cout << guseynov::identifyUniqueChar(arr, uniqueChars, numOfLetters) << "\n";
  free(arr);
  return 0;
}
