#include "matrix.hpp"

std::istream& abramov::input_matrix(std::istream &in, int *mtx, size_t m, size_t n, size_t &read)
{
  for (size_t i = 0; i < m * n; ++i)
  {
    in >> mtx[i];
    ++read;
  }
  return in;
}

void abramov::output_matrix(std::ostream &out, int *mtx, size_t m, size_t n)
{
  for (size_t i = 0; i < m * n; ++i)
  {
    out << mtx[i];
  }
  out << "\n";
}
