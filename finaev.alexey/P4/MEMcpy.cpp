#include "string_conversion.h"

void finaev::MEMcpy(char* new_str, const char* str, size_t dl)
{
  for (size_t i = 0; i < dl; i++)
  {
    new_str[i] = str[i];
  }
}

