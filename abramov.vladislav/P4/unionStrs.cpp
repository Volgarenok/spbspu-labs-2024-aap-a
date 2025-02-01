#include "unionStrs.hpp"
#include <cstddef>

char *abramov::unionStrs(char *destination, const char *str1, const char *str2)
{
  size_t i = 0;
  size_t k = 0;
  while (str1[i] != '\0' && str2[i] != '\0')
  {
    destination[k++] = str1[i];
    destination[k++] = str2[i];
    ++i;
  }
  if (str1[i] == '\0')
  {
    while (str2[i] != '\0')
    {
      destination[k++] = str2[i++];
    }
  }
  else
  {
    while (str1[i] != '\0')
    {
      destination[k++] = str1[i++];
    }
  }
  destination[k] = '\0';
  return destination;
}
