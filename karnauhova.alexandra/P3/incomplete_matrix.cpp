#include "incomplete_matrix.hpp"
#include <new>

void karnauhova::smooth_matrix(const int* t, float* n_mtx, size_t m, size_t n)
{
  int sum = 0;
  size_t k = 0;
  float count = 0;
  for (size_t i = 0; i < m; ++i)
  {
    count = 0;
    sum = 0;
    for (size_t j = 0; j < n; ++j)
    {
      if (j > 0)
      {
        sum += t[j - 1 + k];
        count += 1;
        if (i > 0)
        {
          sum += t[j + k - n - 1];
          count += 1;
        }
        if (i < (m - 1))
        {
          sum += t[j + k + n - 1];
          count += 1;
        }
      }
      if (j < (n - 1))
      {
        sum += t[j + 1 + k];
        count += 1;
        if (i > 0)
        {
          sum += t[j + k - n + 1];
          count += 1;
        }
        if (i < (m - 1))
        {
          sum += t[j + k + n + 1];
          count += 1;
        }
    }
      if (i > 0)
      {
        sum += t[j + k - n];
        count += 1;
      }
      if (i < (m - 1))
      {
        sum += t[j + k + n];
        count += 1;
      }
      n_mtx[j + k] = sum / count;
    }
    k += n;
  }
}
