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

char* averenkov::latTwo(const char* str1, const char* str2)
{
  if (!str1 || !str2)
  {
    return nullptr;
  }
  if (std::strlen(str1) == 0 || std::strlen(str2) == 0)
  {
    char* result = static_cast<char*>(malloc(1));
    if (!result)
    {
      return nullptr;
    }
    result[0] = '\0';
    return result;
  }
  int found[26] = {0};
  size_t length = 0;
  for (size_t i = 0; str1[i] != '\0'; ++i)
  {
    char ch = str1[i];
    if (std::isalpha(static_cast<unsigned char>(ch)))
    {
      ch = std::tolower(static_cast<unsigned char>(ch));
      if (ch >= 'a' && ch <= 'z')
      {
        found[ch - 'a'] = 1;
      }
    }
  }

    for (size_t i = 0; str2[i] != '\0'; ++i) {
        char ch = str2[i];
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            ch = std::tolower(static_cast<unsigned char>(ch));
            if (ch >= 'a' && ch <= 'z') {
                found[ch - 'a'] = 1;
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (found[i] == 1) {
            length++;
        }
    }

    if (length == 0) {
        char* result = static_cast<char*>(malloc(1));
        if (!result) {
            return nullptr;
        }
        result[0] = '\0';
        return result;
    }
    char* result = static_cast<char*>(malloc(length + 1));
    if (!result) {
        return nullptr;
    }
    size_t n = 0;
    for (int i = 0; i < 26; ++i) {
        if (found[i] == 1) {
            result[n++] = 'a' + i;
        }
    }
    result[n] = '\0';
    return result;
}
