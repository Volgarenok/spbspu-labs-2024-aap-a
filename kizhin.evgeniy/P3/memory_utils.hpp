#ifndef MEMORY_UTILS_HPP
#define MEMORY_UTILS_HPP

#include <cstddef>

namespace kizhin {
  enum class MemoryMode { null = 0, stack = 1, freeStore = 2 };
  constexpr size_t stackMemorySize = 10000;

  int* allocateArray(size_t, MemoryMode);
  void deallocateArray(int*, MemoryMode);
}

#endif
