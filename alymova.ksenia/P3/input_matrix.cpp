#include "matrix.h"
#include <cstddef>
#include <istream>
std::istream& alymova::input_matrix(std::istream& input, int* const matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < (rows * cols) && input.good(); i++)
  {
    input >> matrix[i];
  }
  return input;
}
