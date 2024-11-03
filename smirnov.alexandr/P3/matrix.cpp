#include "matrix.hpp"
#include <cstddef>

std::istream & smirnov::inputMatrix(std::istream & input, int * matrix, size_t rows, size_t columns)
{
  for (size_t i = 0; i < rows * columns; i++)
  {
    input >> matrix[i]
  }
  return input;
}

void smirnov::processMatrix(std::ostream & output, int * matrix, int rows, int cols)
{
  int layer = 0;
  int increment = 1;
  while (layer < (min(rows, cols) + 1) / 2)
  {
    for (size_t j = layer; j < cols - layer; ++j)
    {
      matrix[layer][j] += increment;
    }
    increment++;
    for (int i = layer + 1; i < rows - layer; ++i)
    {
      matrix[i][cols - layer - 1] += increment;
    }
    increment++;
    if (rows - layer - 1 > layer)
    {
      for (int j = cols - layer - 1; j >= layer; --j)
      {
        matrix[rows - layer - 1][j] += increment;
      }
      increment++;
    }
    if (cols - layer - 1 > layer)
    {
      for (int i = rows - layer - 2; i > layer; --i)
      {
        matrix[i][layer] += increment;
      }
      increment++;
    }
    layer++;
  }
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      output << matrix[i][j] << " ";
    }
    output << "\n";
  }
}
