#include "latinRemove.h"
#include <cctype>

char* aleksandrov::latinRemove(char* str, int size)
{
  for (int i = 0; i < size; )
  {
    if (std::isalpha(str[i]))
    {
      for (int j = i; j < size - 1; ++j)
      {
        str[j] = str[j + 1];
      }
      str[--size] = '\0';
    }
    else
    {
      ++i;
    }
  }
  return str;
}

