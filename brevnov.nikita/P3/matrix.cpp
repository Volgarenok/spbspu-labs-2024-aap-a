#include "matrix.hpp"

int  brevnov::input_matrix(std::ifstream & in, int * t, size_t m, size_t n)
{
  for (size_t i = 0; i < m * n ; ++i)
  {
    if (!(in >> t[i]))
    {
      return i;
    }
  }
  return m*n;
}

void brevnov::output_matrix(std::ofstream & out, int * t, size_t m, size_t n)
{
  out << t[i];
  for (size_t i = 1; i < m * n; ++i)
  {
    out << " " << t[i];
  }
}