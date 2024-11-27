#include "has_common_chars.hpp"

int kushekbaev::hasCommonChars(const char* str1, const char* str2, size_t size)
{
  for (const char* i = str1; i < str1 + size; i++)
  {
    for (const char* j = str2; j < str2 + size; j++)
    {
      if (str1[i] == str2[j])
      {
        return 1;
      }
    }
  }
  return 0;
}
