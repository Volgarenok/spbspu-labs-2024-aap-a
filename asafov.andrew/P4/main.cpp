#include <iostream>
#include "stringFunctions.hpp"
#include "../../asafov.andrew/common/inputString.hpp"

int main()
{
  char* str = nullptr;
  str = asafov::inputString();
  if(str[0] == '\0')
  {
    delete[] str;
    return 1;
  }

  std::cout << asafov::countUniqLetters(str) << '\n';

  char* unusedLetters = new char[27];
  try
  {
    asafov::getUnusedLetters(str, unusedLetters);
  }
  catch (const std::bad_alloc&)
  {
    delete[] unusedLetters;
    delete[] str;
    return 1;
  }
  for (size_t i = 0; i < 26 || unusedLetters[i] != '\0'; i++)
  {
    std::cout << unusedLetters[i];
  }
  std::cout << '\n';

  delete[] unusedLetters;
  delete[] str;
  return 0;
}
