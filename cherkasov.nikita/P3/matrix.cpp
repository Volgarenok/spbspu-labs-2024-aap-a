#include "matrix.h"
#include <iostream>
#include <fstream>

constexpr size_t max = 1000;
int cherkasov::readMatrix(std::istream& inFile, size_t& rows, size_t& cols, int* matrix)
{
  if (!inFile)
  {
    std::cerr << "Error: Cannot open input file.\n";
    rows = cols = 0;
    return 1;
  }
  if (!(inFile >> rows >> cols))
  {
    std::cerr << "Error: Failed to read matrix dimensions.\n";
    return 1;
  }
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  const size_t totalElements = rows * cols;
  if (totalElements > max)
  {
    std::cerr << "Error: Matrix size exceeds fixed array limit.\n";
    rows = 0;
    cols = 0;
    return 1;
  }
  for (size_t i = 0; i < totalElements; ++i)
  {
    if (!(inFile >> matrix[i]))
    {
      std::cerr << "Error: Invalid matrix format.\n";
      return 1;
    }
  }
  return 0;
}
int cherkasov::countNonZeroDiagonals(const int* matrix, size_t rows, size_t cols)
{
  int count = 0;
  size_t minDim = std::min(rows, cols);
  bool hasZero = false;
  for (size_t i = 0; i < minDim; ++i)
  {
    if (matrix[i * cols + i] == 0)
    {
      hasZero = true;
      break;
    }
  }
  if (!hasZero)
  {
    count++;
  }
  for (size_t k = 1; k < rows; ++k)
  {
    hasZero = false;
    for (size_t i = k, j = 0; i < rows && j < cols; ++i, ++j)
    {
      if (matrix[i * cols + j] == 0)
      {
        hasZero = true;
        break;
      }
    }
    if (!hasZero)
    {
      count++;
    }
  }
  for (size_t k = 1; k < cols; ++k)
  {
    hasZero = false;
    for (size_t i = 0, j = k; i < rows && j < cols; ++i, ++j)
    {
      if (matrix[i * cols + j] == 0)
      {
        hasZero = true;
        break;
      }
    }
    if (!hasZero)
    {
      count++;
    }
  }
  return count;
}
bool cherkasov::isMatrixLowerTriangular(const int* matrix, size_t rows, size_t cols)
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
