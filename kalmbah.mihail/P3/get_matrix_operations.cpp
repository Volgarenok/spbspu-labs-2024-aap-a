#include "get_matrix_operations.h"
#include <fstream>

namespace kalmbah
{

void createSymmetricMatrices(const int matrix[100][100], int result[200][200], int rows, int cols)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      result[i][j] = matrix[i][j];
    }
  }

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      result[2 * rows - 1 - i][j] = matrix[i][j];
    }
  }

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      result[i][2 * cols - 1 - j] = matrix[i][j];
    }
  }

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      result[2 * rows - 1 - i][2 * cols - 1 - j] = matrix[i][j];
    }
  }
}

void createSymmetricMatrices(const int* matrix, int* result, int rows, int cols)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      result[i * (2 * cols) + j] = matrix[i * cols + j];
    }
  }

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      result[(2 * rows - 1 - i) * (2 * cols) + j] = matrix[i * cols + j];
    }
  }

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      result[i * (2 * cols) + (2 * cols - 1 - j)] = matrix[i * cols + j];
    }
  }

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      result[(2 * rows - 1 - i) * (2 * cols) + (2 * cols - 1 - j)] = matrix[i * cols + j];
    }
  }
}

void printMatrix(const int matrix[200][200], int rows, int cols, std::ofstream& outputFile)
{
  outputFile << rows << " " << cols << " ";
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      outputFile << matrix[i][j] << " ";
    }
  }
  outputFile << "\n";
}

void printMatrix(const int* matrix, int rows, int cols, std::ofstream& outputFile)
{
  outputFile << rows << " " << cols << " ";
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      outputFile << matrix[i * cols + j] << " ";
    }
  }
  outputFile << "\n";
}

}
