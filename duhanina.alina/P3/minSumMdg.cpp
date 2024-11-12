#include "functionMatrix.h"
#include <algorithm>
#include <cstring>
/*
int duhanina::minSumMdg(const int * t, size_t m, size_t n)
{
  size_t max_count_diag = m + n - 1;
  int min_sum = std::numeric_limits<int>::max();
  for (size_t sum = 0; sum < max_count_diag; ++sum)
  {
    int current_sum = 0;
    for (size_t i = 0; i < m; ++i)
    {
      size_t j = sum - i;
      if (j >= 0 && j < n_int)
      {
        current_sum += t[i * n + j];
      }
    }
    min_sum = std::min(min_sum, current_sum);
  }
  return min_sum;
}*/
#include <climits>

int duhanina::minSumMdg(const int* matrix, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  size_t minSum = 0;
  for (size_t i = 0, j = cols - 1; i < rows && j >= 0; ++i, --j)
  {
    minSum += matrix[i * cols + j];
  }
  for (size_t startCol = cols - 2; startCol >= 0; --startCol)
  {
    size_t sum = 0;
    for (size_t row = 0, col = startCol; row < rows && col >= 0; ++row, --col)
    {
      sum += matrix[row * cols + col];
    }
    minSum = std::min(minSum, sum);
  }
  for (size_t startRow = 1; startRow < rows; ++startRow)
  {
    size_t sum = 0;
    for (size_t row = startRow, col = cols - 1; row < rows && col >= 0; ++row, --col)
    {
      sum += matrix[row * cols + col];
    }
    minSum = std::min(minSum, sum);
  }
  return minSum;
}
