#include "matrix_functions.hpp"

void dirti::input_matrix(std::istream & in, int * t, size_t m, size_t n, size_t & read)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      if (in >> t[n * i + j])
      {
        ++read;
      }
    }
  }
}
