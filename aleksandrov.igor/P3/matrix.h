#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <cstddef>

namespace aleksandrov
{
  std::istream& inputMatrix(std::istream& input, int* array, size_t size, size_t& read);
  void outputMatrix(std::ostream& output, int* array, size_t m, size_t n);
}
#endif
