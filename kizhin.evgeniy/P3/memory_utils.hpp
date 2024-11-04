#ifndef MEMORY_UTILS_HPP
#define MEMORY_UTILS_HPP

#include <cstddef>

namespace kizhin {
  constexpr size_t stackBufferSize = 10'000;
  enum class MemoryMode { stack = 1, freeStore = 2 };
  int* allocateArray(size_t, int* stackBuffer, MemoryMode);
  void deallocateArray(int*, MemoryMode);
}

#endif
