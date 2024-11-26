#include "countInMtx.hpp"
#include "hasDuplicatesInColumn.hpp"

size_t maslovskiy::countNoDuplicates(const int *matrix, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t j = 0; j < cols; ++j)
  {
    if (!(hasDuplicatesInColumn(matrix, rows, j, cols)))
    {
      ++count;
    }
  }
  return count;
}

