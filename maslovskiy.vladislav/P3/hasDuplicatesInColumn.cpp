#include "hasDuplicatesInColumn.hpp"

bool maslovskiy::hasDuplicatesInColumn(const int *matrix, size_t rows, size_t col, size_t cols)
{
  for (size_t i = 1; i < rows; ++i)
  {
    if (matrix[i * cols + col] == matrix[(i - 1) * cols + col])
    {
      return true;
    }
  }
  return false;
}
