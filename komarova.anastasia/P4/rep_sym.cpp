#include "change.h"
#include <cstddef>
char * komarova::rep_sym(const char * str, char * str_rep)
{
  char * new_str = str_rep;
  while (*str != '\0')
  {
    const char * k = str;
    size_t rep = 0;
    const char * temp_rep = str_rep;
    while (*temp_rep != '\0' && rep != 1)
    {
      if (*str == *temp_rep)
      {
        rep = 1;
      }
      temp_rep++;
    }
    if (rep == 0)
    {
      while (*k != '\0')
      {
        if (*str == *k && str != k)
        {
          *new_str = *str;
          new_str++;
          break;
        }
        k++;
      }
    }
    str++;
  }
  *new_str = '\0';
  return str_rep;
}
