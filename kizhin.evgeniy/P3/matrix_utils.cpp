#include "matrix_utils.hpp"

size_t kizhin::countLocalMinimums(const int* matrix, size_t rows, size_t columns)
{
  if (rows < 2 || columns < 2 || matrix == nullptr) {
    return 0;
  }
  size_t count = 0;
  for (size_t i = 1; i < rows - 1; ++i) {
    for (size_t j = 1; j < columns - 1; ++j) {
      count += isLocalMinimum(matrix, i, j, rows, columns);
    }
  }
  return count;
}

bool kizhin::isLocalMinimum(
    const int* matrix, size_t row, size_t column, size_t rows, size_t columns)
{
  if (column == 0 || column == columns - 1) {
    return false;
  }
  if (row == 0 || row == rows - 1) {
    return false;
  }
  constexpr size_t neighborsSize = 4;
  int neighbors[neighborsSize] = {
    matrix[(row - 1) * columns + column],
    matrix[(row + 1) * columns + column],
    matrix[row * columns + column - 1],
    matrix[row * columns + column + 1],
  };
  int center = matrix[row * columns + column];
  for (size_t i = 0; i < neighborsSize; ++i) {
    if (center >= neighbors[i]) {
      return false;
    }
  }
  return true;
}

std::istream& kizhin::readArrayValues(std::istream& in, int* array, size_t size)
{
  if (array == nullptr || size == 0) {
    return in;
  }
  for (size_t i = 0; i < size; ++i) {
    in >> array[i];
  }
  return in;
}
