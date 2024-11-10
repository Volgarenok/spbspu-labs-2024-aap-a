#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <cstddef>

namespace finaev
{
  void MEMcpy(void* new_a, void* a, size_t n);
  char* increase_str(char* a, char* new_a, size_t old_dl);
  char* creature_str(size_t dl);
  int is_repeat(char* str, size_t dl);
}

#endif
