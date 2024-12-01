#include "input_matrix.hpp"

std::istream& maslevtsov::inputMatrix(std::istream& in, int* matrix, size_t nRows, size_t nColumns)
{
  for (size_t i = 0; i < nRows * nColumns; ++i)
  {
    in >> matrix[i];
  }
  return in;
}
