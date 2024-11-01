#include "matrix.hpp"
#include <cstring>
#include <cctype>

bool mozhegova::isNumber(const char * str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if (!isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}