#include "matrix.h"
#include <cstddef>
#include <istream>
std::istream& alymova::input_matrix(std::istream& input, int* const matrix, size_t& const rows, size_t& const cols)
{
  for (size_t i = 0; i < (rows * cols); i++)
  {
    input >> matrix[i];
  }
  return input;
}
