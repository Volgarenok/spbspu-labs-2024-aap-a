#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

namespace mozhegova
{
  std::istream & inputMatrix(std::istream & in, int * t, size_t m, size_t n, size_t & read);
  bool uppTriMtx(const int * v, size_t m, size_t n);
}

#endif
