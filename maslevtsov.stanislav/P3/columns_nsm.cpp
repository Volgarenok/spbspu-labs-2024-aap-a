#include "columns_nsm.hpp"

bool maslevtsov::isSameElements(const int* const matrix, size_t nRows, size_t nColumns, size_t iColumns)
{
  for (size_t j = 1; j < nRows; ++j)
  {
    if (matrix[(j - 1) * nColumns + iColumns] == matrix[j * nColumns + iColumns])
    {
      return false;
    }
  }
  return true;
}

size_t maslevtsov::countColumnsNSM(const int* const matrix, size_t nRows, size_t nColumns)
{
  for (size_t i = 0; i < nColumns; ++i)
  {
    if (isSameElements(matrix, nRows, nColumns, i))
    {
      return 1;
    }
  }
  return 0;
}
