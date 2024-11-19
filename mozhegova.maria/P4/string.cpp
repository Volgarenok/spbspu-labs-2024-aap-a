#include "string.hpp"
#include <cctype>
#include <iostream>

char * mozhegova::spcRmv(char * str)
{
  size_t i = 0;
  size_t j = 0;
  while (str[i] != '\0')
  {
    if (!std::isspace(str[i]))
    {
      str[j++] = str[i];
    }
    else if (j > 0 && !std::isspace(str[j - 1]))
    {
      str[j++] = ' ';
    }
    i++;
  }
  if (j > 0 && std::isspace(str[j - 1]))
  {
    j--;
  }
  str[j] = '\0';
  return str;
}
