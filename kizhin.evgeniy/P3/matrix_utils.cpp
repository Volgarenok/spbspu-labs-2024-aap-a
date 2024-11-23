#include "matrix_utils.hpp"

size_t kizhin::readArrayValues(std::istream& in, int* array, size_t size)
{
  for (size_t i = 0; i < size; ++i) {
    if (!(in >> array[i])) {
      return i;
    }
  }
  return size;
}

size_t kizhin::countLocalMaximums(const int* matrix)
{
  if (matrix == nullptr || matrix[0] < 2 || matrix[1] < 2) {
    return 0;
  }
  const size_t rows = matrix[0];
  const size_t columns = matrix[1];
  size_t count = 0;
  for (size_t i = 1; i < rows - 1; ++i) {
    for (size_t j = 1; j < columns - 1; ++j) {
      count += isLocalMaximum(matrix, i, j);
    }
  }
  return count;
}

bool kizhin::isLocalMaximum(const int* matrix, size_t row, size_t column)
{
  const size_t rows = matrix[0];
  const size_t columns = matrix[1];
  if (column == 0 || column == columns - 1) {
    return false;
  }
  if (row == 0 || row == rows - 1) {
    return false;
  }
  const size_t index = row * columns + column + 2;
  constexpr size_t adjacentCellsSize = 8;
  int adjacentCells[] = {
    matrix[index - columns - 1],
    matrix[index - columns + 1],
    matrix[index + columns - 1],
    matrix[index + columns + 1],
    matrix[index - columns],
    matrix[index + columns],
    matrix[index - 1],
    matrix[index + 1],
  };
  const int center = matrix[index];
  for (size_t i = 0; i < adjacentCellsSize; ++i) {
    if (center < adjacentCells[i]) {
      return false;
    }
  }
  return true;
}

