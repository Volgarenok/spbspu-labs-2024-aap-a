#include "making_new_cstring.hpp"
#include <cstddef>

char * petrov::makeNewCStringOutOfTwo(char * new_cstring, const char * string_1, const char * numbers)
{
  size_t i = 0;
  size_t j = 0;
  while (string_1[j] != '\0')
  {
    new_cstring[i] = string_1[j];
    i++;
    j++;
  }
  j = 0;
  while (numbers[j] != '\0')
  {
    new_cstring[i] = numbers[j];
    i++;
    j++;
  }
  new_cstring[i] = '\0';
  return new_cstring;
}
