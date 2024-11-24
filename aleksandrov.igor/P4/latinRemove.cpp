#include "latinRemove.h"
#include <cctype>

char* aleksandrov::latinRemove(char* str)
{
  int j = 0;
  for (int i = 0; str[i] != '\0'; ++i)
  {
    if (!std::isalpha(str[i]))
    {
      str[j++] = str[i];
    }
  }
  str[j] = '\0';
  return str;
}

