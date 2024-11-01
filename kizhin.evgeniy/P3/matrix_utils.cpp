#include "matrix_utils.hpp"
#include <new>

int* kizhin::allocateMatrix(size_t rows, size_t columns, int mode)
{
  if (mode == 1) {
    return new (std::nothrow) int[rows * columns];
  } else if (mode == 2) {
    constexpr size_t stackArrayLenght = 1000;
    static int stackArray[stackArrayLenght];
    return stackArray;
  } else {
    return nullptr;
  }
}

size_t kizhin::countLocalMinimums(
    const int* matrix, size_t rows, size_t columns)
{
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
  } else if (row == 0 || row == rows - 1) {
    return false;
  }
  constexpr size_t neighborsCount = 4;
  int neighbors[neighborsCount] = { matrix[(row - 1) * columns + column],
    matrix[(row + 1) * columns + column], matrix[row * columns + column - 1],
    matrix[row * columns + column + 1] };
  int tmp = matrix[row * columns + column];
  for (size_t i = 0; i < neighborsCount; ++i) {
    if (tmp >= neighbors[i]) {
      return false;
    }
  }
  return true;
}

