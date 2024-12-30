#include "string_processing.hpp"

int maslevtsov::isSameSymbols(const char* str1, const char* str2)
{
  for (const char* i = str1; *i != '\0'; ++i)
  {
    for (const char* j = str2; *j != '\0'; ++j)
    {
      if (*i == *j)
      {
        return 1;
      }
    }
  }
  return 0;
}
