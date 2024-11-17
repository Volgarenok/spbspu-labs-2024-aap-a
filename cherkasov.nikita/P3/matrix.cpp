#include "matrix.h"
#include <iostream>
#include <fstream>

constexpr size_t max = 1000;

int** cherkasov::readMatrix(const char* inputFile, size_t& rows, size_t& cols, bool useFixedArray)
{
  std::ifstream inFile(inputFile);
  if (!inFile)
  {
    std::cerr << "Error: Cannot open input file.\n";
    return nullptr;
  }

  if (!(inFile >> rows >> cols))
  {
    rows = 0;
    cols = 0;
    return nullptr;
  }

  if (rows <= 0 || cols <= 0)
  {
    std::cerr << "Error: Invalid matrix format or dimensions.\n";
    return nullptr;
  }

  const size_t totalElements = rows * cols;
  if (useFixedArray && totalElements > max)
  {
    std::cerr << "Error: Matrix size exceeds fixed array limit.\n";
    return nullptr;
  }

  int** matrix = new int*[rows];
  for (size_t i = 0; i < rows; ++i)
  {
    matrix[i] = new int[cols];
  }

  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (!(inFile >> matrix[i][j]))
      {
        std::cerr << "Error: Invalid matrix format.\n";
        for (size_t k = 0; k <= i; ++k)
        delete[] matrix[k];
        delete[] matrix;
        return nullptr;
      }
    }
  }

  return matrix;
}

int cherkasov::processMatrix(int** matrix, size_t rows, size_t cols)
{
  int count = 0;
  size_t minDim = std::min(rows, cols);
  bool hasZero = false;

  for (size_t i = 0; i < minDim; ++i)
  {
    if (matrix[i][i] == 0)
    {
      hasZero = true;
      break;
    }
  }

  if (!hasZero) count++;

  for (size_t k = 1; k < rows; ++k)
  {
    hasZero = false;
    for (size_t i = k, j = 0; i < rows && j < cols; ++i, ++j)
    {
      if (matrix[i][j] == 0)
      {
        hasZero = true;
        break;
      }
    }
    if (!hasZero) count++;
  }

  for (size_t k = 1; k < cols; ++k)
  {
    hasZero = false;
    for (size_t i = 0, j = k; i < rows && j < cols; ++i, ++j)
    {
      if (matrix[i][j] == 0)
      {
        hasZero = true;
        break;
      }
    }
    if (!hasZero) count++;
  }

  return count;
}

void cherkasov::freeMatrix(int** matrix, size_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    delete[] matrix[i];
  }
  delete[] matrix;

}

bool cherkasov::lowerTriangul(int** matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = i + 1; j < cols; ++j)
    {
      if (matrix[i][j] != 0)
      {
        return false;
      }
    }
  }

  return true;
}

