#include "realloc_memory.hpp"
#include <cstdlib>

char* zholobov::realloc_memory(char* p, size_t current_size, size_t new_size)
{
  char* new_p = static_cast< char* >(std::malloc(new_size));
  if (new_p == nullptr) {
    return nullptr;
  }
  if (p == nullptr) {
    return new_p;
  }
  size_t min_size = (current_size > new_size) ? new_size : current_size;
  for (size_t i = 0; i < min_size; ++i) {
    new_p[i] = p[i];
  }
  std::free(p);
  return new_p;
}
