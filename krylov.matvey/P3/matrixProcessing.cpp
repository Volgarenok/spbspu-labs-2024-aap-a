#include "matrixProcessing.hpp"

namespace krylov
{
  int countEqualsInColumn(const int * const matrix, size_t rows, size_t columns, size_t currentColumn);
}

int krylov::countEqualsInColumn(const int * const matrix, size_t rows, size_t columns, size_t currentColumn)
{
  int currentAmountEquals = 0;
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

std::istream & krylov::inputMatrix(std::istream & in, int *matrix, size_t rows, size_t columns)
{
  for (size_t i = 0; i < rows * columns; i++)
  {
    in >> matrix[i];
  }
  return in;
}

int krylov::getColumnWithMaxEquals(const int * const matrix, size_t rows, size_t columns)
{
  int columnWithMaxSeriesEquals = 0;
  int maxSeriesEqualElements = 0;
  for (size_t currentColumn = 0; currentColumn < columns; currentColumn++)
  {
    int currentAmountEquals = krylov::countEqualsInColumn(matrix, rows, columns, currentColumn);
    if (currentAmountEquals > maxSeriesEqualElements)
    {
      maxSeriesEqualElements = currentAmountEquals;
      columnWithMaxSeriesEquals = currentColumn + 1;
    }
  }
  return columnWithMaxSeriesEquals;
}
