#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <iostream>

namespace smirnov
{
  void decrementSpiral(int * matrix, size_t rows, size_t columns);
  bool getLowerTriangularMatrix(int * matrix, size_t rows, size_t columns);
  std::istream & inputMatrix(std::istream & input, int * matrix, size_t sizeMatrix);
  void outputSpiral(std::ostream & output, int * matrix, size_t sizeMatrix);
  void outputFunctions(std::ostream & output, int * matrix, size_t rows, size_t columns, size_t sizeMatrix);
}
#endif
