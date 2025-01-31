#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <istream>

namespace hismatova
{
  std::istream & input_matrix(std::istream & in, int * matrix, size_t m, size_t n, size_t & read);
  int find_longest(const int* matrix, size_t m, size_t n);
}

#endif
