#ifndef KUSHEKBAEV_MATRIX
#define KUSHEKBAEV_MATRIX
#include <cstddef>

namespace kushekbaev
{
  int * createMatrix(size_t rows, size_t columns);
  bool isMinInRow(int* matrix, size_t columns, size_t row, int element);
  bool isMaxInColumn(int* matrix, size_t rows, size_t columns, size_t column, int element);
  int countSaddlePoints(int * matrix, size_t rows, size_t columns);
}

#endif
