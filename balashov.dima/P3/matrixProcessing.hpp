#ifndef MATRIX_PROCESSING_HPP
#define MATRIX_PROCESSING_HPP

#include <cstddef>

namespace balashov
{
  int calculateMinSumSideDiagonal(const int matrix[], size_t column, size_t row);
  int сalculationDiagonal(const int matrix[], long columnNow, size_t columnMax,
    long rowNow, size_t rowMax);
}

#endif
