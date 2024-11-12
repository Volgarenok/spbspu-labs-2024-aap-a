#ifndef MATRIX_H
#define MATRIX_H

#include <istream>
#include <cstddef>

namespace hismatova
{
  std::istream & input_matrix(std::istream & in, int * matrix, size_t m, size_t n, size_t & read);
  int find_longest(int* matrix, size_t m, size_t n);
}

#endif
