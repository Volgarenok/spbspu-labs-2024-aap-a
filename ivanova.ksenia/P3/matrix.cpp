#include "matrix.h"
#include <fstream>

std::istream & ivanova::input_matrix(std::istream & in, int * t, size_t m, size_t n, size_t & read)
{
  for (size_t i = 0; i < (m * n); ++i)
  {
    if (in >> t[i])
    {
      ++read;
    }
  }
  return in;
}

size_t ivanova::num_col_lsr(const int * t, size_t m, size_t n)
{
  size_t max = 0;
  size_t result = 0;
  size_t col  = 0;
  for (size_t i = 0; i < m; i++)
  {
    size_t count = 1;
    for (size_t j = 1; j < n; j++)
    {
      if (t[j * n + i] == t[(j - 1) * n + i])
      {
        count++;
      }
      else
      {
        max = count;
        count = 1;
      }
    }
    max = count;
    if (max > result)
    {
      result = max;
      col = i;
    }
  }
  return col + 1;
}

size_t ivanova::min_sum_mdg(const int * t, size_t m, size_t n)
{
  size_t absoluteMin = 0;
  for (size_t diagCols = n - 2; diagCols < n; diagCols--)
  {
    size_t minSum = 0;
    for (size_t i = 0, j = diagCols; i < m && j < n; i++, j--)
    {
      minSum += t[i * n + j];
    }
    if (absoluteMin > minSum)
    {
      absoluteMin = minSum;
    }
  }
  for (size_t diagRows = 1; diagRows < m; diagRows++)
  {
    size_t minSum = 0;
    for (size_t i = diagRows, j = n - 1; i < m && j < n; i++, j--)
    {
      minSum += t[i * n + j];
    }
    if (absoluteMin > minSum)
    {
      absoluteMin = minSum;
    }
  }
  return absoluteMin;
}
