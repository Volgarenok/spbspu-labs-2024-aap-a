#include "kushekbaev_matrix.hpp"

int * kushekbaev::createMatrix(size_t rows, size_t columns)
{
  return new int[rows * columns];
}
