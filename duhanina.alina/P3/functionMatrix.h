#ifndef FUNCTIONMATRIX_H
#define FUNCTIONMATRIX_H
#include <iostream>

namespace duhanina
{
  std::istream & inputMatrix(std::istream & in, int * t, size_t m, size_t n, size_t & read);
  int minSumMdg(const int* matrix, size_t rows, size_t cols);
}

#endif
