#include "matrix_utils.hpp"

int* kizhin::initializeMatrix(
    std::istream& in, int* stackBuffer, size_t stackSize, MemoryMode mode)
{
  int rows = 0;
  int columns = 0;
  if (!(in >> rows >> columns) || rows < 0 || columns < 0) {
    throw std::logic_error("Failed to read matrix dimensions");
  }
  const size_t size = rows * columns;
  int* matrix = allocateArray(size + 2, stackBuffer, stackSize, mode);
  matrix[0] = rows;
  matrix[1] = columns;
  if (!readArrayValues(in, matrix + 2, size)) {
    deallocateArray(matrix, mode);
    throw std::logic_error("Failed to read matrix from file");
  }
  return matrix;
}

std::istream& kizhin::readArrayValues(std::istream& in, int* array, size_t size)
{
  for (size_t i = 0; i < size; ++i) {
    in >> array[i];
  }
  return in;
}

size_t kizhin::countLocalMinimums(const int* matrix)
{
  if (matrix == nullptr || matrix[0] < 2 || matrix[1] < 2) {
    return 0;
  }
  const size_t rows = matrix[0];
  const size_t columns = matrix[1];
  size_t count = 0;
  for (size_t i = 1; i < rows - 1; ++i) {
    for (size_t j = 1; j < columns - 1; ++j) {
      count += isLocalMinimum(matrix, i, j);
    }
  }
  return count;
}

bool kizhin::isLocalMinimum(const int* matrix, size_t row, size_t column)
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
  constexpr size_t neighborsSize = 4;
  int neighbors[neighborsSize] = {
    matrix[index - columns],
    matrix[index + columns],
    matrix[index - 1],
    matrix[index + 1],
  };
  const int center = matrix[index];
  for (size_t i = 0; i < neighborsSize; ++i) {
    if (center >= neighbors[i]) {
      return false;
    }
  }
  return true;
}

