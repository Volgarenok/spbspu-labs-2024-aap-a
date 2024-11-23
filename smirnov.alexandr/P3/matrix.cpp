#include "matrix.hpp"
#include <cstddef>
#include <iostream>

std::istream & smirnov::inputMatrix(std::istream & input, int * matrix, size_t sizeMatrix)
{
  for (size_t i = 0; i < sizeMatrix; ++i)
  {
    input >> matrix[i];
  }
  return input;
}

void smirnov::decrementSpiral(int * matrix, size_t rows, size_t columns)
{
  size_t row_end = rows;
  size_t col_end = columns;
  size_t decrementer = 0;
  size_t index = 0;
  while (decrementer < rows * columns)
  {
    if (decrementer == rows * columns)
    {
      break;
    }
    for (size_t i = 0; i < col_end; ++i)
    {
      matrix[index++] -= ++decrementer;
    }
    col_end--;
    index--;
    if (decrementer == rows * columns)
    {
      break;
    }
    for (size_t j = 1; j < row_end; ++j)
    {
      index += columns;
      matrix[index] -= ++decrementer;
    }
    row_end--;
    if (decrementer == rows * columns)
    {
      break;
    }
    for (size_t z = 0; z < col_end; ++z)
    {
      matrix[--index] -= ++decrementer;
    }
    col_end--;
    if (decrementer == rows * columns)
    {
      break;
    }
    for (size_t x = 1; x < row_end; ++x)
    {
      index -= columns;
      matrix[index] -= ++decrementer;
    }
    row_end--;
    index++;
  }
}

bool smirnov::checkLowerTriangularMatrix(const int * matrix, size_t rows, size_t columns)
{
  if (rows != columns || rows == 0 || columns == 0)
  {
    return false;
  }
  else
  {
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = i + 1; j < rows; ++j)
      {
        if (matrix[i * rows + j] != 0)
        {
          return false;
        }
      }
    }
    return true;
  }
}

void smirnov::outputMatrix(std::ostream & output, const int * matrix, size_t rows, size_t columns)
{
  if (rows == 0 || columns == 0)
  {
    return;
  }
  else
  {
    output << matrix[0];
    for (size_t i = 1; i < rows * columns; ++i)
    {
      output << " " << matrix[i];
    }
  }
}

void smirnov::outputResult(std::ostream & output, int * matrix, size_t rows, size_t columns)
{
  output << std::boolalpha << smirnov::checkLowerTriangularMatrix(matrix, rows, columns) << "\n";
  output << rows << " " << columns << " ";
  smirnov::decrementSpiral(matrix, rows, columns);
  smirnov::outputMatrix(output, matrix, rows, columns);
  output << "\n";
}
