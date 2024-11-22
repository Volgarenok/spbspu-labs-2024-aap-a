#ifndef MY_REALLOC_HPP
#define MY_REALLOC_HPP

#include <cstddef>

namespace zholobov {
  char* my_realloc(char* p, size_t current_size, size_t new_size);
}

#endif
