#include "matrix.hpp"

void brevnov::input_matrix(std::istream & in, int ** t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      in >> t[i][j];
    }
  }
}

int ** brevnov::alloc(size_t m, size_t n)
{
  
}