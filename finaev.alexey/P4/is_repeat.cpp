#include "functions.h"

int finaev::is_repeat(char* str, size_t dl)
{
  for (size_t i = 0; i < (dl - 1); i++)
  {
    if (str[i] == str[i + 1])
    {
      return 1;
    }
  }
  return 0;
}

