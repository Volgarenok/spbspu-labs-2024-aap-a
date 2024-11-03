#include "kushekbaev_matrix.hpp"

int & kushekbaev::getElement(int * matrix, size_t columns, size_t row, size_t column)
{
  return matrix[row * columns + column];
}
