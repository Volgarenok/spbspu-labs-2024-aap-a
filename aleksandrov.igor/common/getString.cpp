#include "getString.h"
#include <iostream>
#include <ios>
#include <cstddef>

char* aleksandrov::copyString(const char* str, size_t newStrSize)
{
  char* newStr = new char[newStrSize];
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    newStr[i] = str[i];
  }
  return newStr;
}

char* aleksandrov::getString(std::istream& input)
{
  size_t maxSize = 2;
  size_t strSize = 0;
  constexpr const int coef = 2;
  char* str = new char[maxSize + 1];
  char c = '\0';
  std::noskipws(input);
  while (input >> c && c != '\n')
  {
    if (strSize == maxSize)
    {
      maxSize += coef;
      str[strSize] = '\0';
      char* newStr = nullptr;
      try
      {
        newStr = copyString(str, maxSize + 1);
      }
      catch (const std::bad_alloc& e)
      {
        delete[] str;
        throw;
      }
      delete[] str;
      str = newStr;
    }
    str[strSize++] = c;
  }
  std::skipws(input);
  str[strSize] = '\0';
  return str;
}

