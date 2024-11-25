#include "matrix.h"
#include <limits>
size_t bocharov::NumLocMax(const int * matrix, size_t rows, size_t cols)
{
  int max = std::numeric_limits< int >::min();
  size_t result = 0;
  for (size_t i = 1; i < (rows * cols) - 1; i++)
  {
    if ((matrix[i] >= max) && (matrix[i - 1] < matrix[i]) && (matrix[i + 1] < matrix[i]))
    {
      if(matrix[i] == max)
      {
        result++;
      }
      else
      {
        result = 1;
        max = matrix[i];
      }
    }
  }
  if ((result + 2) == rows * cols)
  {
    return 0;
  }
  return result;
}
