#include "matrix_operations.hpp"
#include <istream>

void shabalin::spiralDecrease(int *matrix, size_t rows, size_t cols)
{
  size_t i = 0, j = 0;
  size_t rowBegin = 0, rowEnd = 0, colBegin = 0, colEnd = 0;

  for (size_t k = 1; k < rows * cols; ++k)
  {
    matrix[i * cols + j] = k;
    (i == rowBegin && j < cols - colEnd - 1) ? ++j :
    (j == cols - colEnd - 1 && i < rows - rowEnd - 1) ? ++i :
    (i == rows - rowEnd - 1 && j > colBegin) ? --j : --i;
    (colBegin <= colEnd) ? ++colBegin : (rowBegin <= rowEnd) ? --rowEnd : throw;
  }
  return;
}
