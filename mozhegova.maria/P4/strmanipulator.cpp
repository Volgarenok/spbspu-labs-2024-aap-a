#include "strmanipulator.hpp"
#include <cctype>

char * mozhegova::spcRmv(char * str)
{
  char * orig = str;
  char * res = str;
  bool lastWasSpace = false;
  while (*str)
  {
    if (!std::isspace(*str))
    {
      *res++ = *str;
      lastWasSpace = false;
    }
    else if (res != orig && !lastWasSpace)
    {
      *res++ = ' ';
      lastWasSpace = true;
    }
    str++;
  }
  if (lastWasSpace && res != orig)
  {
    res--;
  }
  *res = '\0';
  return orig;
}
