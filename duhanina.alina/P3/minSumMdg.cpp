#include "minSumMdg.h"
#include <algorithm>
#include <cstring>

int duhanina::minSumMdg(const int* matrix, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  size_t minSum = 0;
  for (size_t i = 0, j = cols - 1; i < rows && j < cols; ++i, --j)
  {
    minSum += matrix[i * cols + j];
  }
  for (size_t startCol = cols - 2; startCol < cols; --startCol)
  {
    size_t sum = 0;
    for (size_t row = 0, col = startCol; row < rows && col < cols; ++row, --col)
    {
      sum += matrix[row * cols + col];
    }
    minSum = std::min(minSum, sum);
  }
  for (size_t startRow = 1; startRow < rows; ++startRow)
  {
    size_t sum = 0;
    for (size_t row = startRow, col = cols - 1; row < rows && col < cols; ++row, --col)
    {
      sum += matrix[row * cols + col];
    }
    minSum = std::min(minSum, sum);
  }
  return minSum;
}
