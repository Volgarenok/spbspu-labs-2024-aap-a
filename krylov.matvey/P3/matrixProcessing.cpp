#include "matrixProcessing.hpp"

namespace krylov
{
  size_t countEqualsInColumn(const int* matrix, size_t rows, size_t columns, size_t currentColumn);
}

size_t krylov::countEqualsInColumn(const int* matrix, size_t rows, size_t columns, size_t currentColumn)
{
  size_t currentAmountEquals = 0;
  for (size_t j = 1; j < rows; j++)
  {
    if (matrix[currentColumn + columns * j] == matrix[currentColumn + columns * (j - 1)])
    {
      currentAmountEquals++;
    }
    else
    {
      currentAmountEquals = 0;
    }
  }
  return currentAmountEquals;
}

std::istream & krylov::inputMatrix(std::istream & in, int* matrix, size_t rows, size_t columns)
{
  for (size_t i = 0; i < rows * columns; i++)
  {
    in >> matrix[i];
  }
  return in;
}

size_t krylov::getColumnWithMaxEquals(const int* matrix, size_t rows, size_t columns)
{
  size_t columnWithMaxSeriesEquals = 0;
  size_t maxSeriesEqualElements = 0;
  for (size_t currentColumn = 0; currentColumn < columns; currentColumn++)
  {
    size_t currentAmountEquals = countEqualsInColumn(matrix, rows, columns, currentColumn);
    if (currentAmountEquals > maxSeriesEqualElements)
    {
      maxSeriesEqualElements = currentAmountEquals;
      columnWithMaxSeriesEquals = currentColumn + 1;
    }
  }
  return columnWithMaxSeriesEquals;
}
