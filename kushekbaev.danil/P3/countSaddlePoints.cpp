#include "kushekbaev_matrix.hpp"

int kushekbaev::countSaddlePoints(int * matrix, size_t rows, size_t columns)
{
  int count = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      int element = kushekbaev::getElement(matrix, columns, i, j);

      bool is_min_in_row = true;
      for (size_t z = 0; z < columns; z++)
      {
        if (kushekbaev::getElement(matrix, columns, i, z) < element)
        {
          is_min_in_row = false;
          break;
        }
      }

      bool is_max_in_column = true;
      for (size_t z = 0; z < rows; z++)
      {
        if (kushekbaev::getElement(matrix, columns, z, j) > element)
        {
          is_max_in_column = false;
          break;
        }
      }

      if (is_min_in_row and is_max_in_column)
      {
        count++;
      }
    }
  }
  return count;
}
