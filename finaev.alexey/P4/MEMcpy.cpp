#include "string_conversion.h"

void finaev::MEMcpy(char* new_a, const char* a)
{
  const char* str_ptr = a;
  while (*str_ptr != '0')
  {
    *new_a = *str_ptr;
    str_ptr++;
    new_a++;
  }
}

