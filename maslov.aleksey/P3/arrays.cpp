#include "arrays.hpp"

std::istream & maslov::inputMatrix(std::istream & in, int** matrix,
    size_t rows, size_t columns, size_t & read)
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

int * maslov::convert(const int* const* matrix, size_t rows,
    size_t columns, int * array)
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

void maslov::destroyMatrix(int** matrix, size_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}

int** maslov::createMatrix(size_t rows, size_t columns)
{
  int** matrix = new int*[rows];
  size_t created = 0;
  try
  {
    for(; created < rows; ++created)
    {
      matrix[created] = new int[columns];
    }
  }
  catch(const std::bad_alloc & e)
  {
    maslov::destroyMatrix(matrix, created);
    throw;
  }
  return matrix;
}

// void maslov::outputMatrix(std::ostream &out);
