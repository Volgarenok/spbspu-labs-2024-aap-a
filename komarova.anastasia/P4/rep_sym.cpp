#include "change.h"
#include <cstddef>
char * komarova::rep_sym(const char * str)
{
  while (*str != '\0')
  {
    const char * k = str;
    size_t rep = 0;
    const char * str_rep = nullptr;
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
