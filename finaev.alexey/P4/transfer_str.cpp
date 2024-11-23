#include "string_conversion.h"

void finaev::transferStr(char* new_str, const char* str, size_t length)
{
  for (size_t i = 0; i < length; i++)
  {
    new_str[i] = str[i];
  }
}

