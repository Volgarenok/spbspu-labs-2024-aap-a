#include "unionString.hpp"
#include <cstddef>

char * smirnov::uniString(char * result_str, const char * str1, const char * str2)
{
  char * resultPtr = result_str;
  const char * ptr1 = str1;
  const char * ptr2 = str2;
  while (*ptr1 != '\0' && *ptr2 != '\0')
  {
    *resultPtr++ = *ptr1++;
    *resultPtr++ = *ptr2++;
  }
  while (*ptr1 != '\0')
  {
    *resultPtr++ = *ptr1++;
  }
  while (*ptr2 != '\0')
  {
    *resultPtr++ = *ptr2++;
  }
  *resultPtr = '\0';
  return result_str;
}
