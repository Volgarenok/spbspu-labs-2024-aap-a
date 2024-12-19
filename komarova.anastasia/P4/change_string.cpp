#include "change.h"
#include <cstddef>
int komarova::vowel(const char* str)
{
  const char * vows = "aeiouAEIOU\0";
  while (*str != '\0')
  {
    for (const char * v = vows; *v != '\0'; v++)
    {
      if (*str == *v)
      {
        return 1;
      }
    }
    str++;
  }
  return 0;
}
char * komarova::vowels(const char * str, char * str_res)
{
  char * res = str_res;
  while (*str != '\0')
  {
    if (vowel(str) || *str == ' ')
    {
      *str_res = *str;
      str_res++;
    }
    str++;
  }
  *str_res = '\0';
  return res;
}
