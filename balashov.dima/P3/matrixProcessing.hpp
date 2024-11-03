#ifndef MATRIX_PROCESSING_HPP
#define MATRIX_PROCESSING_HPP

#include <cstddef>

namespace balashov
{
  int minSumSideDiagonal(const int matrix[], size_t column, size_t row);
  int diagonalCalculation(const int matrix[], int columnNow, size_t columnMax,
    int rowNow, size_t rowMax);
}

#endif
