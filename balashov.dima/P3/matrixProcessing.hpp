#ifndef MATRIX_PROCESSING_HPP
#define MATRIX_PROCESSING_HPP

#include <iostream>
#include <fstream>
#include <cstddef>

namespace balashov
{
  double minSumSideDiagonal(int matrix[], size_t column, size_t row);
  double diagonalCalculation(int matrix[], int columnNow, size_t columnMax,
    int rowNow, size_t rowMax);
}

#endif
