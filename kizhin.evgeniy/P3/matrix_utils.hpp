#ifndef MATRIX_UTILS_HPP
#define MATRIX_UTILS_HPP

#include <istream>
#include "memory_utils.hpp"

namespace kizhin {
  int* initializeMatrix(std::istream&, int* stackBuffer, size_t stackSize, MemoryMode);
  std::istream& readArrayValues(std::istream&, int*, size_t);
  size_t countLocalMinimums(const int*);
  bool isLocalMinimum(const int*, size_t row, size_t column);
}

#endif
