#include "matrix_funcs.h"

int* alloc(size_t k, int c)
{
  int* matrix = nullptr;
  if (c == 1)
  {
    matrix[10000] = {};
  }
  else if (c == 2)
  {
    matrix = new int[n];
  }
  return matrix;
}

std::istream & input_matrix(std::istream & in, int* t, size_t k, size_t & read)
{
  for (size_t i = 0, i < k; ++i)
  {
    if (!(in >> t[i]))
    {
      throw std::logic_error("read fail");
    }
    ++read;
  }
  return in;
}
