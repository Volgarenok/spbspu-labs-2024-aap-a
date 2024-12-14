#include "change.h"
#include <cstddef>
int komarova::vowel(char sym)
{
  if (sym == 'a' || sym == 'e' || sym == 'o' || sym == 'i' || sym == 'u' || sym == 'A' || sym == 'E' || sym == 'O' || sym == 'I' || sym == 'U')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
char * komarova::vowels(const char * str, char * str_res)
{
  for (; *str != '\0'; str++)
  {
    if (komarova::vowel(*str) || *str == ' ')
    {
      *str_res = *str;
      str_res++;
    }
  }
  *str_res = '\0';
  return str_res;
}
