#include "countInMtx.hpp"

size_t maslovskiy::countNoDuplicates(int *matrix, size_t rows, size_t cols)
{
  int count = 0;
  for (size_t j = 0; j < cols; ++j)
  {
    bool hasDupl = false;
    for (size_t i = 1; i < rows; ++i)
    {
      if (matrix[i * cols + j] == matrix[(i - 1) * cols + j])
      {
        hasDupl = true;
        break;
      }
    }
    if (!hasDupl)
    {
      ++count;
    }
  }
  return count;
}
