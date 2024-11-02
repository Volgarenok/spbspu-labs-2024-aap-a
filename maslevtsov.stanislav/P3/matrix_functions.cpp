#include "matrix_functions.hpp"

std::istream & matrixInput(std::istream & in, int * matrix, size_t nRows, size_t nColumns)
{
  for (size_t i = 0; i < nRows * nColumns; ++i)
  {
    in >> matrix[i];
  }
  return in;
}

size_t getNumberOfRequiredColumns(const int * const matrix, size_t nRows, size_t nColumns)
{
  size_t result = 0;

  for (size_t i = 0; i < nColumns; ++i)
  {
    bool flag = true;
    for (size_t j = 1; j < nRows; ++j)
    {
      if (matrix[(j - 1) * nColumns + i] == matrix[j * nColumns + i])
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      ++result;
    }
  }

  return result;
}
