#ifndef KUSHEKBAEV_MATRIX
#define KUSHEKBAEV_MATRIX
#include <cstddef>

namespace kushekbaev
{
  int * createMatrix(size_t rows, size_t columns);
  void deleteMatrix(int * matrix);
  int & getElement(int * matrix, size_t columns, size_t row, size_t column);
  int countSaddlePoints(int * matrix, size_t rows, size_t columns);
}

#endif
