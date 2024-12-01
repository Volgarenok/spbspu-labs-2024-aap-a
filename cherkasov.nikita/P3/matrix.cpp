#include "matrix.h"
#include <iostream>
#include <fstream>

const int max = 10000;

bool cherkasov::readMatrix(const char* inputFile, int**& matrix, int& rows, int& cols, bool useFixedArray)
constexpr size_t max = 1000;
int cherkasov::readMatrix(std::istream& inFile, size_t& rows, size_t& cols, int* matrix)
{
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
  if (useFixedArray && totalElements > max)
  const size_t totalElements = rows * cols;
  if (totalElements > max)
  {
    std::cerr << "Error: Matrix size exceeds fixed array limit.\n";
    return false;
  }

  matrix = new int* [rows];
  for (int i = 0; i < rows; ++i)
  for (size_t i = 0; i < totalElements; ++i)
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
int cherkasov::processMatrix(const int* matrix, size_t rows, size_t cols)
int cherkasov::countNonZeroDiagonals(const int* matrix, size_t rows, size_t cols)
{
  int count = 0;
  int minDim = std::min(rows, cols);
  bool hasZero = false;
  for (int i = 0; i < minDim; ++i)
  {
    if (matrix[i][i] == 0)
    {
      hasZero = true;
      break;
    }
  }
  if (!hasZero) count++;

  for (int k = 1; k < rows; ++k)
  if (!hasZero)
  {
    count++;
  }
  for (size_t k = 1; k < rows; ++k)
  {
    hasZero = false;
    for (int i = k, j = 0; i < rows && j < cols; ++i, ++j)
    {
      if (matrix[i][j] == 0)
      {
        hasZero = true;
        break;
      }
    }
      if (!hasZero) count++;
  }

  for (int k = 1; k < cols; ++k)
  for (size_t k = 1; k < cols; ++k)
  {
    hasZero = false;
    for (int i = 0, j = k; i < rows && j < cols; ++i, ++j)
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

void cherkasov::freeMatrix(int** matrix, int rows)
bool cherkasov::isLowerTriangular(const int* matrix, size_t rows, size_t cols)
bool cherkasov::isMatrixLowerTriangular(const int* matrix, size_t rows, size_t cols)
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
      {
        return false;
      }
    }
  }

    return true;
}

