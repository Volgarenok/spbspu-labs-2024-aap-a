#ifndef MATRIX_OPERATION_HPP
#define MATRIX_OPERATION_HPP

#include <iostream>

namespace kalmbah
{
  std::istream& inputMtx(std::istream& in, int* mtx, size_t columns, size_t rows);
  void mirrorHorizontal(const int* src, int* dest, size_t columns, size_t rows);
  void mirrorVertical(const int* src, int* dest, size_t columns, size_t rows);
  void mirrorCorner(const int* src, int* dest, size_t columns, size_t rows);
  void combineMatrices(const int* original, int* result, size_t columns, size_t rows);
  void outputMtx(std::ostream& out, const int* mtx, size_t columns, size_t rows);
}

#endif
