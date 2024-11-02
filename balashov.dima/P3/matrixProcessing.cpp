#include "matrixProcessing.hpp"
namespace balashov
{
  double minSumSideDiagonal(int matrix[], size_t column, size_t row)
  {
    double minSumSideDiagonals = matrix[0];
    for (size_t i = 0; i < column; i++)
    {
      for (size_t j = 0; j < row; j++)
      {
        bool isSideDiagonal = (j + 1 == row) && (i == 0);
        bool isParallelSideDiagonal = (j + 1 == row) || (i == 0);
        if (isParallelSideDiagonal && isSideDiagonal == false)
        {
          int sumDiagonalNow = diagonalCalculation(matrix, i, column, j, row);
          if (minSumSideDiagonals > sumDiagonalNow)
          {
            minSumSideDiagonals = sumDiagonalNow;
          }
        }
      }
    }
    return minSumSideDiagonals;
  }

  double diagonalCalculation(int matrix[], int columnNow, size_t columnMax,
    int rowNow, size_t rowMax)
  {
    double sumDiagonal = 0;
    while (rowNow >= 0 && columnNow < static_cast<int>(columnMax))
    {
      sumDiagonal += matrix[columnNow * rowMax  + rowNow];
      rowNow--;
      columnNow++;
    }
    return sumDiagonal;
  }
}
