#include "inputMtx.h"
#include <iostream>

std::istream & duhanina::inputMatrix(std::istream & in, int * t, size_t m, size_t n, size_t & read)
{
  for (size_t i = 0; i < (n * m); ++i)
  {
    if (in >> t[i])
    {
      ++read;
    }
  }
  return in;
}
