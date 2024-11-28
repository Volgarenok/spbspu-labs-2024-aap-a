#include "matrix.h"
#include <iostream>

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
  size_t count = 0;
  size_t max = 0;
  size_t result = 0;
  size_t col  = 0;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n - 1; j++)
    {
      if (t[j * m + i] == t[(j + 1) * m + i])
      {
        count++;
      }
      else
      {
        max = count;
        count = 0;
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
    //zavtra......
}