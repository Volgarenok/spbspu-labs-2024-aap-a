#include "stringManipulator.hpp"
#include <cstddef>

char * maslov::excludeCharacters(char * str1, const char * str2)
{
  char * original = str1;
  char * result = str1;
  while (*str1)
  {
    const char * ptr2 = str2;
    bool found = false;
    while (*ptr2 && !found)
    {
      if (*str1 == *ptr2)
      {
        found = true;
      }
      ptr2++;
    }
    if (!found)
    {
      *result++ = *str1;
    }
    str1++;
  }
  *result = '\0';
  return original;
}
