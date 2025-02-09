#include "matrix.h"
void bocharov::change_matrix(int * const matrix, size_t rows, size_t cols)
{
  size_t ibegin = rows - 1, ifinish = 0, jbegin = 0, jfinish = cols - 1, i = rows - 1, j = 0;
  size_t changed = 1, k = 1;
  while (changed < rows * cols + 1)
  {
    matrix[i * cols + j] += k;
    if (i == ibegin && j < jfinish)
    {
      ++j;
    }
    else if (j == jfinish && i > ifinish)
    {
      --i;
    }
    else if (i == ifinish && j > jbegin)
    {
      --j;
    }
    else if (j == jbegin && i < ibegin)
    {
      ++i;
    }
    if ((i == ibegin - 1) && (j == jbegin))
    {
      --ibegin;
      ++ifinish;
      ++jbegin;
      --jfinish;
      ++j;
    }
    ++k;
    ++changed;
  }
}
