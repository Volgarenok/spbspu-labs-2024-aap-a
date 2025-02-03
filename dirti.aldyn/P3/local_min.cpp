#include "matrix_functions.hpp"

int dirti::local_min(const int * matrix, size_t m, size_t n)
{
  int num = 0;
  for (size_t i = 1; i < (m - 1); ++i)
  {
    for (size_t j = 1; j < (n - 1); ++j)
    {
      size_t t = i * n + j;
      if (matrix[t] < matrix[t - 1] && matrix[t] < matrix[t + 1] && matrix[t] < matrix[t - n] && matrix[t] < matrix[t + n])
      {
        ++num;
      }
    }
  }
  return num;
}
