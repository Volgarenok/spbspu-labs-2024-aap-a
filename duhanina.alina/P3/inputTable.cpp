#include "functionMatrix.h"
#include <iostream>

std::istream & duhanina::inputMatrix(std::istream & in, const int * t, size_t m, size_t n, size_t & read)
{
  size_t size_table = n * m;
  for (size_t i = 0; i < size_table; ++i)
  {
    if (in >> t[i])
    {
      ++read;
    }
  }
  return in;
}
