#include "getString.h"
#include <iostream>
#include <ios>
#include <cstddef>

char* aleksandrov::copyString(const char* str, size_t newStrSize)
{
  char* newStr = nullptr;
  newStr = new char[newStrSize];
  for (size_t i = 0; i != '\0'; ++i)
  {
    newStr[i] = str[i];
  }
  delete[] str;
  return newStr;
}

char* aleksandrov::getString(std::istream& input)
{
  size_t maxSize = 16;
  size_t strSize = 0;
  constexpr const int coef = 16;
  char* str = nullptr;
  str = new char[maxSize + 1];
  char c = '\0';
  std::noskipws(input);
  while (input >> c && c != '\n')
  {
    if (strSize == maxSize)
    {
      maxSize += coef;
      str = aleksandrov::copyString(str, maxSize);
    }
    str[strSize++] = c;
  }
  std::skipws(input);
  str[strSize] = '\0';
  return str;
}

