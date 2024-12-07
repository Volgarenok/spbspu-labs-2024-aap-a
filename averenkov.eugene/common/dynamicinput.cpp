#include "dynamicinput.h"
#include <iostream>
#include <cstring>
#include <memory>
#include <stdexcept>

char* averenkov::stringcopy(const char* str, char* new_str)
{
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    new_str[i] = str[i];
  }
  return new_str;
}

char* averenkov::stringInput(std::istream& in)
{
  size_t max = 10;
  constexpr size_t n = 2;
  size_t size = 0;
  char c = '\0';
  in >> std::noskipws;
  char * str = reinterpret_cast< char* >(malloc(max + 1));
  if (str == nullptr)
  {
    in >> std::skipws;
    return nullptr;
  }
  while ((in >> c) && (c != '\n'))
  {
    if (size == max)
    {
      str[max] = '\0';
      max = max * n;
      char * new_str = reinterpret_cast< char* >(malloc(max + 1));
      if (new_str == nullptr)
      {
        free(str);
        in >> std::skipws;
        return nullptr;
      }
      new_str = averenkov::stringcopy(str, new_str);
      free(str);
      str = new_str;
    }
    str[size++] = c;
  }
  in >> std::skipws;
  str[size] = '\0';
  return str;
}
