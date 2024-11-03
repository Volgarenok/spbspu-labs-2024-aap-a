#include "matrix.h"
void alymova::change_matrix(int* const matrix, size_t rows, size_t cols)
{
  size_t ibegin = rows - 1, ifinish = rows - 1, jbegin = 0, jfinish = 0, i = rows - 1, j = 0;
  int k = 1;
  while (k < rows * cols)
  {
    matrix[i * j + j + 1] = k;
    if (i == ibegin && j < cols - jfinish - 1)
    {
      ++j;
    }
    else if (j == cols - jfinish - 1 && i > rows - ifinish - 1)
    {
      --i;
    }
    else if (i == rows - ifinish - 1 && j > jbegin)
    {
      --j;
    }
    else if (j == jbegin && i < ibegin)
    {
      ++i;
    }
    if ((i == ibegin - 1) && (j == jbegin) && (jbegin != cols - jfinish - 1))
    {
      --ibegin;
      --ifinish;
      ++jbegin;
      ++jfinish;
    }
    ++k;
  }
}
