#include "dynamicinput.h"
#include <iostream>
#include <cstring>
#include <memory>
#include <stdexcept>

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
      size_t new_size = max * n;
      char* str_new = reinterpret_cast< char* >(realloc(str, new_size));
      if (str_new == nullptr)
      {
        free(str);
        in >> std::skipws;
        return nullptr;
      }
      str = str_new;
      max = new_size;
    }
    str[size++] = c;
  }
  in >> std::skipws;
  str[size] = '\0';
  return str;
}
