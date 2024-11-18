#include "arraymoves.h"
#include <memory>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

char* averenkov::newArray(char* first, char* second)
{
  for(size_t i = 0; first[i] != '\0'; i++)
  {
    second[i] = first[i];
  }
  free (first);
  return second;
}

char* averenkov::stringInput(std::istream& in, char* str)
{
  size_t max = 10;
  const size_t n = 2;
  size_t size = 0;
  char c = '\0';
  std::noskipws(in);
  while ((in >> c) && (c != '\n'))
  {
    if (size == max - 1)
    {
      char* str_new = reinterpret_cast<char*> (malloc(((size * n) + 1) * sizeof(char)));
      if(str_new == nullptr)
      {
        free(str_new);
        return nullptr;
      }
      str_new[size * n] = '\0';
      str = averenkov::newArray(str, str_new);
      if (str == nullptr)
      {
        free (str);
        return nullptr;
      }
      max *= n;
      str[size] = c;
    }
    else
    {
      str[size] = c;
    }
    size++;
  }
  std::skipws(in);
  return str;
}

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
