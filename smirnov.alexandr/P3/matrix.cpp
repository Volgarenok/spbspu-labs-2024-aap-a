#include "matrix.hpp"
#include <cstddef>

std::istream & smirnov::inputMatrix(std::istream & input, int * matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    input >> matrix[i];
  }
  return input;
}

void smirnov::processMatrix(int * matrix, size_t rows, size_t columns)
{
  int row_start = 0;
  int row_end = rows - 1;
  int cols_start = 0;
  int cols_end = cols - 1;
  int k = 1;
  int index = 0;
  while (row_start <= row_end && col_start <= col_end)
  {
    for (size_t i = col_start; i <= col_end && index < rows * columns; ++i)
    {
      matrix[index++] -= k++;
    }
    row_start++;
    for (size_t j = row_start; j <= row_end && index < rows * columns; ++j)
    {
      matrix[index++] -= k++;
    }
    col_end--;
    if (row_start <= row_end)
    {
      for (size_t i = col_end; i >= col_start && index < rows * columns; --i)
      {
        matrix[index++] -= k++;
      }
      row_end--;
    }
    if (col_start <= col_end)
    {
      for (size_t j = row_end; j > row_start; --j)
      {
        matrix[index++] -= k++;
      }
      col_start++;
    }
    layer++;
}
