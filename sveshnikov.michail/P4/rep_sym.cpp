#include "rep_sym.hpp"

char *sveshnikov::rep_sym(const char *str, char *new_str)
{
  char * next = new_str;
  for (const char * i = str; *i != '\0'; i++)
  {
    const char * j = str;
    char * k = new_str;
    std::size_t repetition = 0;
    while (*k != '\0' && repetition != 1)
    {
      if (*i == *k)
      {
        repetition = 1;
      }
      k++;
    }
    if (repetition == 0)
    {
      while (*j != '\0' && repetition != 1)
      {
        if (*i == *j && i != j)
        {
          *next = *i;
          repetition = 1;
          next++;
        }
        j++;
      }
    }
  }
  return new_str;
}
