#include "arraymoves.h"
#include <memory>
#include <cstring>
#include <cctype>
#include <cstdlib>

char* averenkov::latTwo(const char* str1, const char* str2)
{
  if (!str1 || !str2)
  {
    return nullptr;
  }
  int found[26] = {0};
  size_t length = 0;
  if(str1[0] != '\0')
  {
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
  }
  if(str2[0] != '\0')
  {
    for (size_t i = 0; str2[i] != '\0'; ++i)
    {
      char ch = str2[i];
      if (std::isalpha(static_cast<unsigned char>(ch)))
      {
        ch = std::tolower(static_cast<unsigned char>(ch));
        if (ch >= 'a' && ch <= 'z')
        {
          found[ch - 'a'] = 1;
        }
      }
    }
  }
  for (int i = 0; i < 26; ++i)
  {
    if (found[i] == 1)
    {
      length++;
    }
  }
  if (length == 0)
  {
    char* result = static_cast<char*>(malloc(1));
    if (!result)
    {
      return nullptr;
    }
    result[0] = '\0';
    return result;
  }
  char* result = static_cast<char*>(malloc(length + 1));
  if (!result)
  {
    return nullptr;
  }
  size_t n = 0;
  for (int i = 0; i < 26; ++i)
  {
    if (found[i] == 1)
    {
      result[n++] = 'a' + i;
    }
  }
  result[n] = '\0';
  return result;
}
