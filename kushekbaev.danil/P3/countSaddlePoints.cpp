#include "count_saddle_point.hpp"

namespace kushekbaev
{
  int & getElement(const size_t columns, const size_t row, const size_t column);
  bool isMinInRow(const size_t columns, const size_t row, const int element);
  bool isMaxInColumn(const size_t rows, const size_t columns, const size_t column, const int element);
}

int & kushekbaev::getElement(const size_t columns, const size_t row, const size_t column)
{
  int* temp_matrix = new int[row * columns + column];
  if (!temp_matrix)
  {
  delete[] temp_matrix;
  std::cerr << "Failed to create temporary matrix in getElement";
  return 1
  }
  return temp_matrix;
}

bool kushekbaev::isMinInRow(const size_t columns,
 const size_t row, const int element)
{
  for (size_t z = 0; z < columns; z++)
  {
    if (getElement(columns, row, z) < element)
    {
      return false;
    }
  }
  return true;
}

bool kushekbaev::isMaxInColumn(const size_t rows,
 const size_t columns, const size_t column, int element)
{
  for (size_t z = 0; z < rows; z++)
  {
    if (getElement(columns, z, column) > element)
    {
      return false;
    }
  }
  return true;
}

int kushekbaev::countSaddlePoints(const size_t rows, const size_t columns)
{
  int count = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      int element = getElement(columns, i, j);

      if (isMinInRow(columns, i, element) && isMaxInColumn(rows, columns, j, element))
      {
        count++;
      }
    }
  }
return count;
}
