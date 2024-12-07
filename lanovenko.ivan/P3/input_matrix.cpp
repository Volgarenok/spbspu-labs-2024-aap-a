#include "input_matrix.h"
#include <stdexcept>

std::istream& lanovenko::input_matrix(std::istream& in, int* matrix, size_t matrixsize)
{
  for (size_t i = 0; i < matrixsize; i++)
  {
    in >> matrix[i];
  }
  return in;
}
