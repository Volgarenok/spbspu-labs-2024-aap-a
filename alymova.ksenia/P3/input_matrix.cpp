#include "cmd_parameters.h"
#include <cstddef>
#include <iostream>
std::istream& alymova::input_matrix(std::istream& input, int* const matrix, size_t& rows, size_t& cols, size_t& read)
{
  for (size_t i = 0; i < (rows * cols) && input.good(); i++)
  {
    input >> matrix[i];
    if (input.good())
    {
      read += 1;
    }
  }
  return input;
}
