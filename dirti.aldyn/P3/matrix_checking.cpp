#include "matrix_functions.hpp"

bool dirti::matrix_checking(const int * matrix, size_t m, size_t n)
{
  for (size_t i = 1; i < (m - 1); ++i)
  {
    for (size_t j = 1; j < (n - 1); ++j)
    {
      if (matrix[i * n + j] != 0)
      {
        return false;
      }
    }
  }
  return true;
}
