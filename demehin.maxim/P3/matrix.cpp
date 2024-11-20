#include "matrix.h"

std::istream & demehin::input_matrix(std::istream& in, int* t, size_t k, size_t & read)
{
  for (size_t i = 0; i < k; ++i)
  {
    in >> t[i];
    ++read;
  }
  return in;
}
