#include "arrays.hpp"

std::istream &maslov::inputMatrix(std::istream &in, int *matrix,
    size_t rows, size_t columns, size_t &read)
{
  for (size_t i = 0; i < rows * columns; i++)
  {
    in >> matrix[i];
    ++read;
  }
  return in;
}
size_t maslov::findLocalMaximum(const int *array, size_t rows, size_t columns)
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
