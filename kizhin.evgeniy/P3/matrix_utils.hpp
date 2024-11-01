#ifndef MATRIX_UTILS_HPP
#define MATRIX_UTILS_HPP

#include <cstddef>

namespace kizhin {
  int* allocateMatrix(size_t, size_t, int mode);
  size_t countLocalMinimums(const int*, size_t, size_t);
  bool isLocalMinimum(
      const int*, size_t row, size_t column, size_t rows, size_t columns);
}
#endif
