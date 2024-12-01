#include "inputMatrix.hpp"
#include <stdexcept>

void maslovskiy::inputMatrix(std::istream &in, int *matrix, size_t matrixSize)
{
  for (size_t i = 0; i < matrixSize; ++i)
  {
    in >> matrix[i];
    if (!in)
    {
      break;
    }
  }
}
