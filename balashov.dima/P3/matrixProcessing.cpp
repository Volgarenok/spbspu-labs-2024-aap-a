#include "matrixProcessing.hpp"

int balashov::calculateMinSumSideDiagonal(const int matrix[], size_t column, size_t row)
{
  int minSumSideDiagonals = matrix[0];
  for (size_t i = 0; i < column; ++i)
  {
    for (size_t j = 0; j < row; ++j)
    {
      bool isSideDiagonal = (j + 1 == row) && (i == 0);
      bool isParallelSideDiagonal = (j + 1 == row) || (i == 0);
      if (isParallelSideDiagonal && !isSideDiagonal)
      {
        int sumDiagonalNow = сalculationDiagonal(matrix, i, column, j, row);
        if (minSumSideDiagonals > sumDiagonalNow)
        {
          minSumSideDiagonals = sumDiagonalNow;
        }
      }
    }
  }
  return minSumSideDiagonals;
}

int balashov::сalculationDiagonal(const int matrix[], long columnNow, size_t columnMax,
  long rowNow, size_t rowMax)
{
  int sumDiagonal = 0;
  while (rowNow >= 0 && columnNow < static_cast<long>(columnMax))
  {
    sumDiagonal += matrix[columnNow * rowMax + rowNow];
    rowNow--;
    columnNow++;
  }
  return sumDiagonal;
}
