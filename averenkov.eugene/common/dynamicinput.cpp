#include "dynamicinput.h"
#include <iostream>
#include <cstring>
#include <memory>
#include <stdexcept>

char* averenkov::arrayresize(char* str, size_t size)
{
  char* str_new = reinterpret_cast< char* >(malloc(size));
  for (size_t i = 0; i < size; ++i)
  {
    str_new[i] = str[i];
  }
  free(str);
  return str_new;
}

char* averenkov::stringInput(std::istream& in)
{
  size_t max = 10;
  const size_t n = 2;
  size_t size = 0;
  char c = '\0';
  in >> std::noskipws;
  char * str = reinterpret_cast< char* >(malloc(max));
  if (str == nullptr)
  {
    free(str);
    in >> std::skipws;
    return nullptr;
  }
  while ((in >> c) && (c != '\n'))
  {
    if (size == max)
    {
      max = max * n;
      str = averenkov::arrayresize(str, max);
      if (str == nullptr)
      {
        free(str);
        in >> std::skipws;
        return nullptr;
      }
    }
    str[size++] = c;
  }
  in >> std::skipws;
  str[size] = '\0';
  return str;
}
