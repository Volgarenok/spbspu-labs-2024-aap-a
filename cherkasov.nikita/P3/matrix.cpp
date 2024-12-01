#include "matrix.h"
#include <iostream>
#include <fstream>
#include <algorithm>

constexpr size_t max = 1000;
bool cherkasov::readMatrix(std::istream& in, size_t& rows, size_t& cols, int* matrix)
{
  if (!(in >> rows >> cols) || rows == 0 || cols == 0)
  {
    return false;
  }
  size_t totalElements = rows * cols;
  for (size_t i = 0; i < totalElements; ++i)
  {
    if (!(in >> matrix[i]))
    {
      return false;
    }
  }
  return true;
}

int cherkasov::processMatrix(const int* matrix, size_t rows, size_t cols)
{
  size_t minDim = std::min(rows, cols);
  int count = 0;
  for (size_t k = 0; k < minDim; ++k)
  {
    bool hasZero = false;
    for (size_t i = 0; i < rows && i + k < cols; ++i)
    {
      if (matrix[i * cols + (i + k)] == 0)
      {
        hasZero = true;
        break;
      }
    }
    if (!hasZero)
    {
      ++count;
    }
  }
  return count;
}

bool cherkasov::lowerTriangular(const int* matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = i + 1; j < cols; ++j)
    {
      if (matrix[i * cols + j] != 0)
      {
        return false;
      }
    }
  }
  return true;
}
