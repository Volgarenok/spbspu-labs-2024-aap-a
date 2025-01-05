#include "strconversion.h"
#include <iostream>
#include <cstddef>
#include <cstring>
char* lanovenko::inputStr(std::istream& in, char stop)
{
  size_t capacity = 10;
  char* str = new char[capacity];
  size_t quantity = 0;
  char c = '\0';
  in >> std::noskipws;
  while (in >> c && c != stop)
  {
    if (quantity >= capacity - 1)
    {
      capacity *= 2;
      char* new_str = nullptr;
      try
      {
        new_str = new char[capacity];
      }
      catch (const std::bad_alloc & e)
      {
        in >> std::skipws;
        delete[] str;
        throw;
      }
      for (size_t i = 0; i < quantity; i++)
      {
        new_str[i] = str[i];
      }
      delete[] str;
      str = new_str;
    }
    str[quantity++] = c;
  }
  str[quantity] = '\0';
  in >> std::skipws;
  return str;
}

void lanovenko::transformationStr(const char* str, char* missing)
{
  size_t index = 0;
  for (char c = 'a'; c <= 'z'; c++)
  {
    bool present = false;
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
      if (std::isalpha(str[i]) && std::tolower(str[i]) == c)
      {
        present = true;
        break;
      }
    }
    if (!present)
    {
      missing[index++] = c;
    }
  }
  missing[index] = '\0';
}
