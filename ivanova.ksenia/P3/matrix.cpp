#include <iostream>

std::istream & input_matrix(std::istream & in, int ** t, size_t m, size_t n, size_t & read)
{
  for (size_t i = 0; i < (m * n); ++i)
  {
    if (in >> t[i])
    {
      ++read;
    }
  }
  return in;
}
