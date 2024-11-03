#include "matrix.hpp"

int  brevnov::input_matrix(std::istream & in, int * t, size_t m, size_t n)
{
  int member = 0;
  for (size_t i = 0; i < m * n ; ++i)
  {
    if (!(in >> t[i]))
    {
      return member;
    }
    else
    {
      ++member;
    }
  }
  return member;
}

int * brevnov::alloc(size_t m, size_t n)
{
  int * t = nullptr;
  t = new int[m * n];
  return t;
}
