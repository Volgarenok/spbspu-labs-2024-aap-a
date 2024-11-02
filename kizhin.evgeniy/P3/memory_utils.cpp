#include "memory_utils.hpp"
#include <stdexcept>

int* kizhin::allocateArray(size_t size, MemoryMode mode)
{
  if (size == 0) {
    return nullptr;
  }
  if (mode == MemoryMode::freeStore) {
    return new int[size];
  }
  if (mode == MemoryMode::stack && size <= stackMemorySize) {
    static int stackArray[stackMemorySize];
    return stackArray;
  }
  throw std::logic_error("Invalid memory allocation request");
}

void kizhin::deallocateArray(int* matrix, MemoryMode mode)
{
  if (mode == MemoryMode::freeStore) {
    delete[] matrix;
  }
}

