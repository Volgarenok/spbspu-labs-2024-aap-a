#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace smirnov
{
  void processMatrix(int * matrix, size_t rows, size_t columns);
  std::istream & inputMatrix(std::istream & input, int * matrix, size_t rows, size_t cols);
}
#endif
