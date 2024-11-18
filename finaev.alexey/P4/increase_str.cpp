#include "string_conversion.h"
#include "cstdlib"

void finaev::MEMcpy(char* new_a, char* a, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    new_a[i] = a[i];
  }
}

char* finaev::increase_str(char* a, char* new_a, size_t old_dl)
{
  finaev::MEMcpy(new_a, a, old_dl);
  free(a);
  return new_a;
}
