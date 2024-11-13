#ifndef MATRIX_FUNCTIONS_HPP
#define MATRIX_FUNCTIONS_HPP

#include <iostream>

namespace maslevtsov
{
  std::istream& matrixInput(std::istream& in, int* matrix, size_t nRows, size_t nColumns);
  bool isSameElements(const int* const matrix, size_t nRows, size_t nColumns, size_t iColumns);
  size_t countColumnsNSM(const int* const matrix, size_t nRows, size_t nColumns);
}

#endif
