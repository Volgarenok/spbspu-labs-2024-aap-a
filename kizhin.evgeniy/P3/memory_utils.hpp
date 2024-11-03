#ifndef MEMORY_UTILS_HPP
#define MEMORY_UTILS_HPP

#include <cstddef>

namespace kizhin {
  enum class MemoryMode { stack = 1, freeStore = 2 };
  int* allocateArray(size_t, int* stackBuffer, size_t stackSize, MemoryMode);
  void deallocateArray(int*, MemoryMode);
}

#endif
