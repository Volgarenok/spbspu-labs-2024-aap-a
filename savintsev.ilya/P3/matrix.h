#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include <iostream>

namespace savintsev
{
  std::istream & inputMtx(std::istream & in, int * t, size_t m, size_t n);
  void outputMtx(std::ostream & out, const int * t, size_t m, size_t n);
  void spiralIncreaseMtx(int * t, size_t m, size_t n);
  size_t processMtx(std::istream & in, std::ostream & out, int * table, int m, int n);
}

#endif
