#include "has_common_chars.hpp"

int kushekbaev::hasCommonChars(const char* str1, const char* str2, size_t size, size_t size_string_literal)
{
  for (const char* i = str1; i < str1 + size; i++)
  {
    for (const char* j = str2; j < str2 + size_string_literal; j++)
    {
      if (*i == *j)
      {
        return 1;
      }
    }
  }
  return 0;
}
