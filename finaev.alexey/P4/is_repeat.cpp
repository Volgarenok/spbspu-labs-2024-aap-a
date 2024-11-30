#include "string_conversion.h"

int finaev::checkRepeat(const char* str)
{
  const char* str_ptr1 = str;
  const char* str_ptr2 = nullptr;
  while (*str_ptr1)
  {
    str_ptr2 = str_ptr1 + 1;
    while (*str_ptr2)
    {
      if (*str_ptr1 == *str_ptr2)
      {
        return 1;
      }
      str_ptr2++;
    }
    str_ptr1++;
  }
  return 0;
}

