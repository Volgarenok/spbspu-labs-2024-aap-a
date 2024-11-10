#include "matrix.hpp"
#include <cstddef>
#include <iostream>

std::istream & smirnov::inputMatrix(std::istream & input, int * matrix, size_t rows, size_t columns)
{
  for (size_t i = 0; i < rows * columns; ++i)
  {
    input >> matrix[i];
  }
  return input;
}

void smirnov::lft_top_clk(int * matrix, size_t rows, size_t columns)
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

bool smirnov::lwr_tri_mtx(int * matrix, size_t rows)
{
  if (rows != columns)
  {
    return false;
  }
  else
  {
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < rows; ++j)
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

void smirnov::lft_top_clkOutput(std::ostream & output, int * matrix, size_t rows, size_t columns)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < columns; ++j)
    {
      output << matrix[i * columns + j] << " ";
    }
  output << "\n";
  }
}

void smirnov::lwr_tri_mtxOutput(std::ostream & output, int * matrix, size_t rows, size_t columns)
{
  if (lwr_tri_mtxOutput(matrix, rows, columns))
  {
    std::cout << "true";
  }
  else
  {
    std::cout << "false";
  }
}
