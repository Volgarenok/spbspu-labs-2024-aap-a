#include "change.h"
#include <cstddef>
char * komarova::rep_sym(const char * str,char * str_rep)
{
  char * new_str = str_rep;
  const char * i = str;
  for (; *i != '\0'; i++)
  {
    const char * k = str;
    size_t rep = 0;
    char * s = str_rep;
    while (*s != '\0' && rep != 1)
    {
      if (*i == *s)
      {
        rep = 1;
      }
      s++;
    }
    if (rep == 0)
    {
      while (*k != '\0' && rep != 1)
      {
        if (*i == *k && i != k)
        {
          *new_str = *i;
          *(new_str + 1) = '\0';
          rep = 1;
          new_str++;
        }
        k++;
      }
    }
  }
  return str_rep;
}
