#include "matrix_funcs.h"

int* demehin::alloc(size_t k, int c)
{
  int* matrix = nullptr;
  if (c == 1)
  {
    matrix[10000] = {};
  }
  else if (c == 2)
  {
    matrix = new int[k];
  }
  return matrix;
}

std::istream & demehin::input_matrix(std::istream & in, int* t, size_t k, size_t & read)
{
  for (size_t i = 0; i < k; ++i)
  {
    in >> t[i];
    ++read;
  }
  return in;
}
