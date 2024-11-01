#include "output_matrix.h"
#include <iostream>

int output_matrix(int *matrix, size_t str, size_t stl)
{
  int res = 0;
  for (size_t i = 0; i < str; i++)
  {
    for (size_t j = 1; j < (stl - 1); j++)
    {
      if (matrix[i][j - 1] < matrix[i][j] && matrix[i][j + 1] < matrix[i][j])
      {
        res += 1;
      }
    }
  }
  return res;
}
