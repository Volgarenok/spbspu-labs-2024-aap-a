#include "input_output.hpp"

std::istream & karnauhova::input_matrix(std::istream & in, int * t, size_t m, size_t n, size_t & read)
{
  for (size_t i = 0; i < (m * n); ++i)
  {
    in >> t[i];
    read++;
  }
  return in;
}
void karnauhova::output_matrix(std::ostream & out, int * t, size_t m, size_t n)
{
  for (size_t i = 0; (i + 1) < (m * n); ++i)
  {
    out << t[i] << ' ';
  }
  out << t[m * n - 1];
}
