#ifndef MATRIX_UTILS_HPP
#define MATRIX_UTILS_HPP

#include <istream>

namespace kizhin {
  size_t readArrayValues(std::istream&, int*, size_t);
  size_t countLocalMaximums(const int*);
  bool isLocalMaximum(const int*, size_t row, size_t column);
}

#endif
