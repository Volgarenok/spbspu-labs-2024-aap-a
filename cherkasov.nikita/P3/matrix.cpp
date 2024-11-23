#include "matrix.h"
#include <iostream>
#include <fstream>

constexpr size_t max = 1000;

int cherkasov::createMatrix(size_t rows, size_t cols, int*** matrix)
{
  *matrix = new int*[rows];
  for (size_t i = 0; i < rows; ++i)
  {
    (*matrix)[i] = new int[cols];
  }
  return 0;
}

int cherkasov::fillMatrix(std::ifstream& inFile, size_t rows, size_t cols, int** matrix)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (!(inFile >> matrix[i][j]))
      {
        std::cerr << "Error: Invalid matrix format.\n";
        return 1;
      }
    }
  }

  return 0;
}

int cherkasov::readMatrix(const char* inputFile, size_t& rows, size_t& cols, bool useFixedArray, int*** matrix)
{
  std::ifstream inFile(inputFile);
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
  if (useFixedArray && totalElements > max)
  {
    std::cerr << "Error: Matrix size exceeds fixed array limit.\n";
    rows = cols = 0;
    return 1;
  }

  if (createMatrix(rows, cols, matrix) != 0)
  {
    return 1;
  }

  if (fillMatrix(inFile, rows, cols, *matrix) != 0)
  {
    freeMatrix(*matrix, rows);
    return 1;
  }

  return 0;
}

void cherkasov::freeMatrix(int** matrix, size_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
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
      if (matrix[i][j] == 0) {
        hasZero = true;
        break;
      }
    }
    if (!hasZero) count++;
  }

  return count;
}

bool cherkasov::lowerTriangul(const int** matrix, size_t rows, size_t cols)
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
