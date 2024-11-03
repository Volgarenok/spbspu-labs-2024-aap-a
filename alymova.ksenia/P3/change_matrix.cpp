#include "matrix.h"
void alymova::change_matrix(int* const matrix, size_t rows, size_t cols)
{
  size_t Ibeg = rows - 1, Ifin = rows - 1, Jbeg = 0, Jfin = 0, i = rows - 1, j = 0;
  int k = 1;
  while (k < rows * cols)
  {
    matrix[i * j + j + 1] = k;
    if (i == Ibeg && j < cols - Jfin - 1)
    {
      ++j;
    }
    else if (j == cols - Jfin - 1 && i > rows - Ifin - 1)
    {
      --i;
    }
    else if (i == rows - Ifin - 1 && j > Jbeg)
    {
      --j;
    }
    else if (j == Jbeg && i < Ibeg)
    {
      ++i;
    }
    if ((i == Ibeg - 1) && (j == Jbeg) && (Jbeg != cols - Jfin - 1))
    {
      --Ibeg;
      --Ifin;
      ++Jbeg;
      ++Jfin;
    }
    ++k;
  }
}
