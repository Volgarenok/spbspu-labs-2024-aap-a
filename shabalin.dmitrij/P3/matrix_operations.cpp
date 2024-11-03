#include "matrix_operations.hpp"
#include <istream>

void shabalin::spiralDecrease(int *matrix, size_t rows, size_t cols)
{
  size_t k = 1;
  size_t i = 0;
  size_t j = 0;
  size_t rowBegin = 0, rowEnd = 0, colBegin = 0, colEnd = 0;

  while (k <= rows * cols)
  {
    matrix[i * cols + j] = k;
    if (i == rowBegin && j < cols - colEnd - 1)
    {
      ++j;
    }
    else if (j == cols - colEnd - 1 && i < rows - rowEnd - 1)
    {
      ++i;
    }
    else if (i == rows - rowEnd - 1 && j > colBegin)
    {
     --j;
    }
    else
    {
     --i;
    }

    if ((i == rowBegin + 1) && (j == colBegin) && (colBegin != cols - colEnd - 1))
    {
      ++rowBegin;
      ++rowEnd;
      ++colBegin;
      ++colEnd;
    }
    ++k;
  }

  return;
}
