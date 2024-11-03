#include "mtxlogic.h"

bool tkach::isNumber(const char * const number)
{
  bool flag = true;
  for (size_t i = 0; number[i] != '\0'; ++i)
  {
    if (!((number[i] >= '0') && (number[i] <= '9')))
    {
      if (number[i] != '-' && (i != 0))
      {
        flag = false;
      }
    }
  }
  return flag;
}
