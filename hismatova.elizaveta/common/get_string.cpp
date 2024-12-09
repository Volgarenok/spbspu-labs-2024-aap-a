#include "get_string.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

char* hismatova::get_line(std::istream& input, size_t& length)
{
  size_t n = 500;
  char *str = reinterpret_cast< char* >(malloc(sizeof(char) * n));
  if (str == nullptr)
  {
    length = 0;
    return nullptr;
  }
  length = 0;
  char c;
  while (input.get(c))
  {
    if (c == '\n')
    {
      break;
    }
    if (length + 1 >= n)
    {
      size_t newSize = n * 2;
      char *newStr = reinterpret_cast< char* >(malloc(sizeof(char) * newSize));
      if (newStr == nullptr)
      {
        free(str);
        length = 0;
        return nullptr;
      }
      for (size_t i = 0; i < length; i++)
      {
        newStr[i] = str[i];
      }
      free(str);
      str = newStr;
      n = newSize;
    }
    str[length++] = c;
  }
  str[length] = '\0';
  return str;
}
