#include "matrix.h"
#include <iostream>
#include <fstream>

const int MAX_SIZE = 10000;

bool cherkasov::readMatrix(const char* inputFile, int**& matrix, int& rows, int& cols, bool useFixedArray)
constexpr size_t max = 1000;
int cherkasov::readMatrix(const char* inputFile, size_t& rows, size_t& cols, bool useFixedArray, int* matrix)
{
  std::ifstream inFile(inputFile);
  if (!inFile)
  {
    std::cerr << "Error: Cannot open input file.\n";
    return false;
  }

  if (!(inFile >> rows >> cols) || rows < 0 || cols < 0)
  {
    std::cerr << "Error: Invalid matrix format or dimensions.\n";
     return false;
  }

  if (rows == 0 || cols == 0)
  {
    matrix = nullptr;
    return true;
  }

  int totalElements = rows * cols;
  if (useFixedArray && totalElements > MAX_SIZE)
  {
    std::cerr << "Error: Matrix size exceeds fixed array limit.\n";
    return false;
  }

  matrix = new int* [rows];
  for (int i = 0; i < rows; ++i)
  {
    matrix[i] = new int[cols];
    for (int j = 0; j < cols; ++j)
    {
      if (!(inFile >> matrix[i][j]))
      {
        std::cerr << "Error: Invalid matrix format.\n";
        for (int k = 0; k <= i; ++k) delete[] matrix[k];
        delete[] matrix;
        return false;
      }
    }
  }

  return true;
}

int cherkasov::processMatrix(int** matrix, int rows, int cols)
{
  int count = 0;
  int minDim = std::min(rows, cols);
  bool hasZero = false;
  for (int i = 0; i < minDim; ++i)
  {
    if (matrix[i][i] == 0)
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

int cherkasov::processMatrix(const int* matrix, size_t rows, size_t cols)
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

  if (!hasZero) count++;

  for (int k = 1; k < rows; ++k)
  {
    hasZero = false;
    for (int i = k, j = 0; i < rows && j < cols; ++i, ++j)
    {
      if (matrix[i][j] == 0)

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
      if (!hasZero) count++;
  }

  for (int k = 1; k < cols; ++k)
  {
    hasZero = false;
    for (int i = 0, j = k; i < rows && j < cols; ++i, ++j)
    {
      if (matrix[i][j] == 0)
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
      if (!hasZero) count++;
  }

  return count;
}

void cherkasov::freeMatrix(int** matrix, int rows)
{
  for (int i = 0; i < rows; ++i)
  {
    delete[] matrix[i];
  }
    delete[] matrix;
}

bool cherkasov::lowerTriangul(int** matrix, int rows, int cols)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = i + 1; j < cols; ++j)
    {
      if (matrix[i][j] != 0)
    if (!hasZero)
    {
      count++;
    }
  }
  return count;
}

bool cherkasov::lowerTriangul(const int* matrix, size_t rows, size_t cols)
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

  return true;
}

