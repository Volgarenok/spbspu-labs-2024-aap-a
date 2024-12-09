#include "stream.hpp"

std::istream & balashov::inputMatrix(std::istream & in, int * matrix, size_t column,
  size_t row, size_t & read)
{
  size_t count = row * column;
  for (size_t i =0; i < count; ++i)
  {
    if (!(in >> matrix[i]))
    {
      ++read;
    }
  }
  return in;
}

