#ifndef MATRIX_H
#define MATRIX_H

#include <istream>
#include <cstddef>

namespace hismatova
{
  std::istream & input_matrix(std::istream & in, int * matrix, size_t m, size_t n, size_t & read);
  void output_matrix(std::ostream & out, int * matrix, size_t m, size_t n);
  void change_matrix(int * matrix, size_t m, size_t n);
  int find_longest(int * matrix, int size);
}

#endif
