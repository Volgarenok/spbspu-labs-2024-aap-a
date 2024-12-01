#include "check_string.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

void hismatova::uniqueChar(const char* str1, const char* str2, char* result)
{
  bool arr[128] = {0};
  for (size_t i = 0; str1[i] != '\0'; ++i)
  {
    int ascii1 = static_cast< int >(str1[i]);
    if (std::islower(str1[i]))
    {
      arr[ascii1] = true;
    }
    if (std::isupper(str1[i]))
    {
      arr[std::tolower(str1[i])] = true;
    }
  }
  for (size_t i = 0; str2[i] != '\0'; ++i)
  {
    int ascii2 = static_cast< int >(str2[i]);
    if (std::islower(str2[i]))
    {
      arr[ascii2] = true;
    }
    if (std::isupper(str2[i]))
    {
      arr[std::tolower(str2[i])] = true;
    }
  }
  size_t ind = 0;
  for (size_t i = 0; i < 128; ++i)
  {
    if (arr[i])
    {
      result[ind++] = static_cast< char >(i);
    }
  }
  result[ind] = '\0';
}
char* hismatova::getLine(std::istream& input)
{
  size_t n = 500;
  char *str = reinterpret_cast< char* >(malloc(sizeof(char) * n));
  if (str == nullptr)
  {
    return nullptr;
  }
  size_t length = 0;
  char c;
  while (input.get(c))
  {
    if (c == '\n')
    {
      break;
    }
    if (length + 1 >= n)
    {
      size_t newSize = n * 2;
      char *newStr = reinterpret_cast< char* >(malloc(sizeof(char) * newSize));
      if (newStr == nullptr)
      {
        free(str);
        return nullptr;
      }
      for (size_t i = 0; i < length; i++)
      {
        newStr[i] = str[i];
      }
      free(str);
      str = newStr;
      n = newSize;
    }
    str[length++] = c;
  }
  str[length] = '\0';
  return str;
}
