#include "memory_utils.hpp"
#include <stdexcept>

int* kizhin::allocateArray(size_t size, int* stackBuffer, size_t stackSize, MemoryMode mode)
{
  if (size == 0) {
    return nullptr;
  }
  if (mode == MemoryMode::freeStore) {
    return new int[size];
  }
  if (mode == MemoryMode::stack && size <= stackSize) {
    return stackBuffer;
  }
  throw std::logic_error("Invalid memory allocation request");
}

void kizhin::deallocateArray(int* matrix, MemoryMode mode)
{
  if (mode == MemoryMode::freeStore) {
    delete[] matrix;
  }
}

