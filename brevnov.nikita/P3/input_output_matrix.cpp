#include "input_output_matrix.hpp"

int  brevnov::input_matrix(std::istream & in, int * t, size_t m, size_t n)
{
  for (size_t i = 0; i < m * n ; ++i)
  {
    if (!(in >> t[i]))
    {
      return i;
    }
  }
  return m * n;
}

void brevnov::output_matrix(std::ostream & out, const int * t, size_t m, size_t n)
{
  out << m << " " << n;
  if ((m != 0) && (n != 0))
  {
    out << " " << t[0];
  }
  for (size_t i = 1; i < m * n; ++i)
  {
    out << " " << t[i];
  }
}
