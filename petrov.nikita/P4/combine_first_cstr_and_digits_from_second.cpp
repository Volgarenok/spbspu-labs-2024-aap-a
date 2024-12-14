#include "making_new_cstring.hpp"
#include <cstddef>
#include <cctype>

char * petrov::combineFirstCStrAndDigitsFromSecond(char * new_cstring, const char * string_1, const char * string_2)
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
  while (string_2[j] != '\0')
  {
    if (std::isdigit(string_2[j]))
    {
      new_cstring[i] = string_2[j];
      i++;
    }
    j++;
  }
  new_cstring[i] = '\0';
  return new_cstring;
}
