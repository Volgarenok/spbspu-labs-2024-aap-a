#include "memory_utils.hpp"
#include <new>

int* kizhin::allocateArray(size_t size, MemoryMode mode)
{
  if (size == 0) {
    return nullptr;
  }
  if (mode == MemoryMode::freeStore) {
    return new (std::nothrow) int[size];
  }
  if (mode == MemoryMode::stack) {
    static int stackArray[stackMemorySize];
    return stackArray;
  }
  return nullptr;
}

void kizhin::deallocateArray(int* matrix, MemoryMode mode)
{
  if (mode == MemoryMode::freeStore) {
    delete[] matrix;
  }
}

