#include "recursionfunc.hpp"

const char * mozhegova::hasLetter(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= 'A' and *str <= 'E') ? (str + 1) : nullptr;
}
