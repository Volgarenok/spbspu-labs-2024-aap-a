#include "strconversion.h"
#include <cstddef>
#include <cstring>
char* lanovenko::inputstring(std::istream& in, const char stop)
{
  size_t capacity = 1;
  char* str = nullptr;
  try
  {
    str = new char[capacity];
  }
  catch (const std::bad_alloc & e)
  {
    delete[] str;
    throw std::logic_error("Out of memory\n");
  }
  size_t quantity = 0;
  char c = '\0';
  in >> std::noskipws;
  while (in >> c && c != stop)
  {
    if (!isalpha(c))
    {
      delete[] str;
      throw std::logic_error("Not a letter");
    }
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
        delete[] new_str;
        delete[] str;
        throw std::logic_error("Out of memory\n");
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
