#include "getString.h"

char* aleksandrov::getString(std::istream& input, size_t& strSize)
{
  size_t maxSize = 10;
  constexpr const int coef = 2;
  char* str = nullptr;
  str = new char[maxSize + 1];
  char c = '\0';
  std::noskipws(input);
  while (input >> c && c != '\n')
  {
    if (strSize == maxSize)
    {
      maxSize += coef;
      char* newStr = nullptr;
      newStr = new char[maxSize + 1];
      for (size_t i = 0; i < maxSize - coef; ++i)
      {
        newStr[i] = str[i];
      }
      delete[] str;
      str = newStr;
    }
    str[strSize++] = c;
  }
  std::skipws(input);
  if (!input && c != '\n')
  {
    throw std::logic_error("ERROR: Input was incorrect!\n");
  }
  str[strSize] = '\0';
  return str;
}

