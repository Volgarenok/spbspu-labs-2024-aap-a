#include "change.h"
#include <cstddef>
char * komarova::rep_sym(const char * str, char * str_rep)
{
  char * new_str = str_rep;
  for (; *str != '\0'; str++)
  {
    const char * k = str;
    size_t rep = 0;
    while (*str_rep != '\0' && rep != 1)
    {
      if (*str == *str_rep)
      {
        rep = 1;
      }
      str_rep++;
    }
    if (rep == 0)
    {
      while (*k != '\0' && rep != 1)
      {
        if (*str == *k && str != k)
        {
          *new_str = *str;
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
