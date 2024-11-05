#include <cstring>
#include <cctype>
#include <iostream>
#include "matrix.hpp"

bool sharifullina::isNumber(const char * str)
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
