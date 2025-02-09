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
