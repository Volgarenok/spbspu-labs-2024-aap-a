#include "string_conversion.h"

int finaev::is_repeat(char* str, size_t dl)
{
  for (size_t i = 0; i < (dl - 1); i++)
  {
    for (size_t j = i + 1; j < dl; j++)
    {
      if (str[i] == str[j])
      {
        return 1;
      }
    }
  }
  return 0;
}

