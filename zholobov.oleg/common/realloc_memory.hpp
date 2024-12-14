#ifndef REALLOC_MEMORY_HPP
#define REALLOC_MEMORY_HPP

#include <cstddef>

namespace zholobov {
  char* realloc_memory(char* p, size_t current_size, size_t new_size);
}

#endif
