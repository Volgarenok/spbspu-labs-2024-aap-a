#include <iostream>
#include <inputString.hpp>
#include "stringFunctions.hpp"

int main()
{
  char* str = asafov::inputString(std::cin);
  if (str[0] == '\0')
  {
    delete[] str;
    return 1;
  }

  std::cout << asafov::countUniqLetters(str) << '\n';

  char unusedLetters[26] = {};
  asafov::getUnusedLetters(str, unusedLetters);
  std::cout << unusedLetters << '\n';

  delete[] str;
  return 0;
}
