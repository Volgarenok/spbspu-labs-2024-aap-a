#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <fstream>

namespace smirnov
{
  void processMatrix(int * matrix, int rows, int columns);
  std::istream & inputMatrix(std::istream & input, int * matrix, size_t rows, size_t columns);
}
#endif
