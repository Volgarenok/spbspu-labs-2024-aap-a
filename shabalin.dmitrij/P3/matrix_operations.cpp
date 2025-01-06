#include "matrix_operations.hpp"

void shabalin::spiralDecrease(int *matrix, size_t rows, size_t cols)
{
  size_t i = 0, j = 0;
  size_t rowStart = 0, rowEnd = 0, colStart = 0, colEnd = 0;

  for (size_t k = 1; k < rows * cols; ++k)
  {
    matrix[i * cols + j] = k;
    (i == rowStart && j < cols - colEnd - 1) ? ++j :
    (j == cols - colEnd - 1 && i < rows - rowEnd - 1) ? ++i :
    (i == rows - rowEnd - 1 && j > colStart) ? --j : --i;
    if ((i == rowStart + 1) && (j == colStart) && (colStart != cols - colEnd - 1))
    {
      ++rowStart;
      ++rowEnd;
      ++colStart;
      ++colEnd;
    }
  }
  return;
}
