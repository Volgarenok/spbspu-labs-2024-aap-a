#include "latinRemove.h"
#include <cctype>
#include <cstddef>

char* aleksandrov::latinRemove(char* str)
{
  size_t j = 0;
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    if (!std::isalpha(str[i]))
    {
      str[j++] = str[i];
    }
  }
  str[j] = '\0';
  return str;
}

