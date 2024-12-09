#include "cnt_nzr_dig.hpp"

size_t sveshnikov::cnt_nzr_dig(const int *matrix, size_t num_rows, size_t num_columns)
{
  size_t num_diagonal = 0;
  for (size_t i = 0; i < num_rows; i++)
  {
    size_t count_zero = 0;
    for (size_t j = 0; j < num_columns * (num_rows - 1); j += num_columns)
    {
      if (matrix[i + j] == 0)
      {
        count_zero++;
      }
    }
    if (count_zero == 0)
    {
      num_diagonal++;
    }
  }
  return num_diagonal;
}
