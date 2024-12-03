#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <iostream>

namespace smirnov
{
  void decrementSpiral(int * matrix, size_t rows, size_t columns);
  bool checkLowerTriangularMatrix(const int * matrix, size_t rows, size_t columns);
  std::istream & inputMatrix(std::istream & input, int * matrix, size_t sizeMatrix);
  void outputMatrix(std::ostream & output, const int * matrix, size_t rows, size_t columns);
  void outputResult(std::ostream & output, int * matrix, size_t rows, size_t columns);
}
#endif
