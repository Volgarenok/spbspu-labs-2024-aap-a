#include "matrixInputAndProcessing.hpp"
#include <iostream>
#include <fstream>

std::istream & krylov::inputMatrix(std::istream & in, int * matrix, size_t rows, size_t columns)
{
  for (size_t i = 0; i < rows * columns; i++)
  {
    in >> matrix[i];
  }
  return in;
}

int krylov::getColumnWithMaxEquals(int * matrix, size_t rows, size_t columns)
{
  int maxColumnWithEquals = 0;
  int maxSeriesEqualElements = 0;
  for (size_t i = 0; i < columns; i++)
  {
    int currentAmountEquals = 0;
    for (size_t j = 1; i < rows; i++)
    {
      if (matrix[i + columns * j] == matrix[i + columns * (j - 1)])
      {
        currentAmountEquals++;
      }
      if (currentAmountEquals > maxSeriesEqualElements)
      {
	maxSeriesEqualElements = currentAmountEquals;
	maxColumnWithEquals = i + 1;
      }
    }
  }
  return maxColumnWithEquals;
}
