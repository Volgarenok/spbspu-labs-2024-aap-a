#include "incomplete_matrix.hpp"
#include <new>
#include <cmath>

float* karnauhova::smooth_matrix(int* t,size_t m,size_t n)
{
  float* n_mtx = nullptr;
  try
  {
    n_mtx = new float[m*n];
  }
  catch (const std::bad_alloc &e)
  {
    delete[] n_mtx;
    throw;
  }
  int sum = 0;
  size_t k = 0;
  float count = 0;
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      if (j != 0)
      {
        sum += t[j - 1 + k];
        count+=1;
        if (i != 0)
        {
          sum += t[j + k - n - 1];
          count+=1;
        }
        if (i != (m - 1))
        {
          sum += t[j + k + n - 1];
          count+=1;
        }
      }
      if (j != (n - 1))
      {
        sum += t[j + 1 + k];
        count+=1;
        if (i != 0)
        {
          sum += t[j + k - n + 1];
          count+=1;
        }
        if (i != (m - 1))
        {
          sum += t[j + k + n + 1];
          count+=1;
        }
      }
      if (i != 0)
      {
        sum += t[j + k - n];
        count+=1;
      }
      if (i != (m - 1))
      {
        sum += t[j + k + n];
        count+=1;
      }
    n_mtx[j+k] = round(sum/count * 10) / 10;;
    }
    k += n;
  }
  return n_mtx;
}
