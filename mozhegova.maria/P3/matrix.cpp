#include "matrix.hpp"

std::istream & mozhegova::inputMatrix(std::istream & in, int * t, size_t m, size_t n, size_t & read)
{
  size_t v = m * n;
  for (size_t i = 0; i < v; i++)
  {
    if (in >> t[i])
    {
      read++;
    }
    else
    {
      return in;
    }
  }
  return in;
}

bool mozhegova::uppTriMtx(const int * v, size_t m, size_t n)
{
  if (m != n)
  {
    return false;
  }
  size_t step = 0;
  for (size_t k = m + 1; k < n * m; k += m + 1)
  {
    step++;
    for (size_t i = 1; i <= step; i++)
    {
      if (v[k - i] != 0)
      {
        return false;
      }
    }
  }
  return true;
}
