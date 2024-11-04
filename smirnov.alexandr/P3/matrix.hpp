#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <iostream>

namespace smirnov
{
  void processMatrix(int * matrix, size_t rows, size_t columns);
  std::istream & inputMatrix(std::istream & input, int * matrix, size_t rows, size_t cols);
  void outputMatrix(std::ostream & output, int * matrix, size_t rows, size_t columns);
}
#endif
