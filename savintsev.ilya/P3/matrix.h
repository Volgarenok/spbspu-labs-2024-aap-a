#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include <iostream>

namespace savintsev
{
  std::istream& inputMtx(std::istream& in, int* t, size_t m, size_t n, size_t& count);
  void outputMtx(std::ostream& out, int* t, size_t m, size_t n);
  void transformMtx(int* t, size_t m, size_t n);
}

#endif
