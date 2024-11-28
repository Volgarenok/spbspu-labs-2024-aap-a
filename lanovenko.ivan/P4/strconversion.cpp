#include "strconversion.h"
#include <iostream>
#include <cstddef>
#include <cstring>
char* lanovenko::inputstring(std::istream& in, const char stop)
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

char* lanovenko::transformationstr(char* str)
{
  bool present[26] = { false };
  int len = strlen(str);

  for (int i = 0; i < len; i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      present[str[i] - 'a'] = true;
    }
  }
  static char missing[27];
  int index = 0;

  for (char ch = 'a'; ch <= 'z'; ch++)
  {
    if (!present[ch - 'a'])
    {
      missing[index++] = ch;
    }
  }
  missing[index] = '\0';
  return missing;
}
