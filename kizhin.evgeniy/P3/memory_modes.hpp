#ifndef MEMORY_MODES_HPP
#define MEMORY_MODES_HPP

#include <cstddef>

namespace kizhin {
  enum class MemoryMode { null = 0, stack = 1, freeStore = 2 };
  constexpr size_t stackMemorySize = 10000;
}

#endif
