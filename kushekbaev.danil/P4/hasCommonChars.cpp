#include "has_common_chars.hpp"

int kushekbaev::hasCommonChars(const char* str1, const char* str2)
{
  for (const char* i = str1; i < str1; i++)
  {
    for (const char* j = str2; j < str2; j++)
    {
      if (*i == *j)
      {
        return 1;
      }
    }
  }
  return 0;
}
