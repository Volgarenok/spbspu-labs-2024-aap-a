#include "titleMatrix.h"

bool duhanina::isDig(char * ch)
{
  size_t i = 0;
  while (ch[i] != "\0")
  {
    if (ch[i] < '0' || ch[i] > '9')
    {
      return false;
    }
    ++i;
  }
  return true;
}
