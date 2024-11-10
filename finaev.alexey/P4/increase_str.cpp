#include "functions.h"
#include "cstdlib"

void finaev::MEMcpy(void* new_a, void* a, size_t n)
{
  char* cnew_a = static_cast<char*> (new_a);
  char* ca = static_cast<char*> (a);
  for (size_t i = 0; i < n; i++)
  {
    cnew_a[i] = ca[i];
  }
}

char* finaev::increase_str(char* a, char* new_a, size_t old_dl)
{
  finaev::MEMcpy(new_a, a, old_dl);
  free(a);
  a = new_a;
  return a;
}
