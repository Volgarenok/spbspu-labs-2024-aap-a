#include "str_functions.hpp"
#include <cstddef>

char *abramov::unionStrs(char *destination, const char *source)
{
  char str[32768] = "\0";
  size_t i = 0;
  size_t k = 0;
  while (destination[i] != '\0' && source[i] != '\0')
  {
    str[k++] = destination[i];
    str[k++] = source[i];
    ++i;
  }
  while (destination[i] != '\0')
  {
    str[k++] = destination[i++];
  }
  while (source[i] != '\0')
  {
    str[k++] = source[i++];
  }
  str[k] = '\0';
  for (size_t j = 0; j < k + 1; ++j)
  {
    destination[j] = str[j];
  }
  return destination;
}
