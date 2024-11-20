#include "dynamicinput.h"
#include <iostream>
#include <cstring>
#include <memory>
#include <stdexcept>

char* averenkov::stringInput(std::istream& in, char* str)
{
  size_t max = 10;
  const size_t n = 2;
  size_t size = 0;
  char c = '\0';
  in >> std::noskipws;
  str = reinterpret_cast<char*>(malloc(max * sizeof(char)));
  if (str == nullptr)
  {
    free(str);
    return nullptr;
  }
  while ((in >> c) && (c != '\n'))
  {
    if (size == max)
    {
      size_t new_size = max * n;
      char* str_new = reinterpret_cast<char*>(realloc(str, new_size * sizeof(char)));
      if (str_new == nullptr)
      {
        free(str);
        return nullptr;
      }
      str = str_new;
      max = new_size;
    }
    str[size++] = c;
  }
  in >> std::skipws;
  if (size == max)
  {
    char* str_new = reinterpret_cast<char*>(realloc(str, (max + 1) * sizeof(char)));
    if (str_new == nullptr)
    {
      free(str);
      return nullptr;
    }
    str = str_new;
  }
  str[size] = '\0';
  return str;
}
