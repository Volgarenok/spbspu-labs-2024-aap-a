#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstddef>

namespace aleksandrov
{
  std::istream& inputMatrix(std::istream& input, int* array, size_t m, size_t n);
  void outputMatrix(std::ostream& output, const int* array, size_t m, size_t n);
}

#endif

