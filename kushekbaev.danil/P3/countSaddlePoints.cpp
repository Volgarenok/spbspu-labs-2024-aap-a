#include "kushekbaev_matrix.hpp"

int & kushekbaev::getElement(int * matrix, size_t columns, size_t row, size_t column)
{
  return matrix[row * columns + column];
}

bool kushekbaev::isMinInRow(int* matrix, size_t columns, size_t row, int element)
{
  for (size_t z = 0; z < columns; z++)
  {
    if (kushekbaev::getElement(matrix, columns, row, z) < element)
    {
      return false;
    }
  }
  return true;
}

bool kushekbaev::isMaxInColumn(int* matrix, size_t rows, size_t columns, size_t column, int element)
{
  for (size_t z = 0; z < rows; z++)
  {
    if (kushekbaev::getElement(matrix, columns, z, column) > element)
    {
      return false;
    }
  }
  return true;
}

int kushekbaev::countSaddlePoints(int * matrix, size_t rows, size_t columns)
{
  int count = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      int element = kushekbaev::getElement(matrix, columns, i, j);

      bool is_min_in_row = isMinInRow(matrix, columns, i, element);

      bool is_max_in_column = isMaxInColumn(matrix, rows, columns, j, element);

      if (is_min_in_row && is_max_in_column)
      {
        count++;
      }
    }
  }
  return count;
}
