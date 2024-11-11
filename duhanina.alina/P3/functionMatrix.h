#ifndef FUNCTIONMATRIX_H
#define FUNCTIONMATRIX_H
#include <iostream>

namespace duhanina
{
  std::istream & inputMatrix(std::istream & in, int * t, size_t m, size_t n, size_t & read);
  int minSumMdg(int * t, size_t m, size_t n);
}

#endif
