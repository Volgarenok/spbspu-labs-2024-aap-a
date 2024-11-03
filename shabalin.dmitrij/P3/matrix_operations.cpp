#include "matrix_operations.hpp"
#include <istream>

void shabalin::spiralDecrease(int *matrix, size_t rows, size_t cols)
{
  size_t k = 1;
  size_t rowBegin = 0, rowEnd = rows - 1, colBegin = 0, colEnd = cols - 1;

  while (rowBegin <= rowEnd && colBegin <= colEnd)
  {
    for (size_t j = colBegin; j <= colEnd; ++j)
    {
      matrix[rowBegin * cols + j] = k++;
    }
    rowBegin++;

    for (size_t i = rowBegin; i <= rowEnd; ++i)
    {
      matrix[i * cols + colEnd] = k++;
    }
    colEnd--;

    if (rowBegin <= rowEnd)
    {
      for (size_t j = colEnd; j >= colBegin; --j)
      {
        matrix[rowEnd * cols + j] = k++;
      }
      rowEnd--;
    }

    if (colBegin <= colEnd)
    {
      for (size_t i = rowEnd; i >= rowBegin; --i)
      {
        matrix[i * cols + colBegin] = k++;
      }
      colBegin++;
    }
  }
}
