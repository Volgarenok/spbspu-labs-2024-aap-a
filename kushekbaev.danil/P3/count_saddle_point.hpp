#ifndef COUNT_SADDLE_POINT
#define COUNT_SADDLE_POINT
#include <cstddef>

namespace kushekbaev
{
  int & getElement(int * matrix, size_t columns, size_t row, size_t column);
  bool isMinInRow(int* matrix, size_t columns, size_t row, int element);
  bool isMaxInColumn(int* matrix, size_t rows, size_t columns, size_t column, int element);
  int countSaddlePoints(int * matrix, size_t rows, size_t columns);
}

#endif
