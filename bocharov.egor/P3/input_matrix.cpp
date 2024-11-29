#include "matrix.h"
#include <istream>
#include <cstddef>
std::istream & bocharov::input_matrix(std::istream & in, int * matrix, size_t rows, size_t cols, size_t & read)
{
  for (size_t i = 0; i < (rows * cols) && in.good(); i++)
  {
    if (in >> matrix[i])
    {
      read++;
    }
  }
  return in;
}
