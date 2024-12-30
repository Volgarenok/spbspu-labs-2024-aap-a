#include <iostream>
#include "stringFunctions.hpp"
#include "../../asafov.andrew/common/inputString.hpp"

int main()
{
  char* str = asafov::inputString();
  if(str[0] == '\0')
  {
    delete[] str;
    return 1;
  }

  std::cout << asafov::countUniqLetters(str) << '\n';

  char* unusedLetters = new char[26];
  asafov::getUnusedLetters(str, unusedLetters);
  std::cout << unusedLetters << '\n';

  delete[] unusedLetters;
  delete[] str;
  return 0;
}
