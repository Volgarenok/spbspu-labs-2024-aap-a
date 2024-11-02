#include "arrays.hpp"

std::istream &maslov::inputMatrix(std::istream &in, int **matrix,
    size_t rows, size_t columns, size_t &read)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      in >> matrix[i][j];
    }
    ++read;
  }
  return in;
}
int *maslov::convert(const int *const *matrix, size_t rows,
    size_t columns, int *array)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      array[i * columns + j] = matrix[i][j];
    }
  }
  return array;
}
void maslov::destroyMatrix(int **matrix, size_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}
int **maslov::createMatrix(size_t rows, size_t columns)
{
  int **matrix = new int*[rows];
  size_t created = 0;
  try
  {
    for (; created < rows; ++created)
    {
      matrix[created] = new int[columns];
    }
  }
  catch (const std::bad_alloc &e)
  {
    maslov::destroyMatrix(matrix, created);
    throw;
  }
  return matrix;
}
size_t maslov::findLocalMaximum(int *array, size_t rows, size_t columns)
{
  size_t count = 0;
  for (size_t i = 1; i < rows - 1; i++)
  {
    for (size_t j = 1; j < columns - 1; j++)
    {
      size_t index = i * columns + j;
      int current = array[index];
      int left = array[index - 1];
      int right = array[index + 1];
      int up = array[index - columns];
      int down = array[index + columns];
      bool isLocalMaximum = (current > left) && (current > right);
      isLocalMaximum = isLocalMaximum && ((current > up) && (current > down));
      if (isLocalMaximum)
      {
        count++;
      }
    }
  }
  return count;
}
