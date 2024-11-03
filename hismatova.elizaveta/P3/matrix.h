#ifndef MATRIX_H
#define MATRIX_H

#include <istream>
#include <cstddef>

namespace hismatova
{
  std::istream & input_matrix(std::istream & in, int * matrix, size_t m, size_t n, size_t & read);
  void output_result(std::ostream & out, int * matrix, size_t m, size_t n);
  int find_longest(int * matrix, size_t m, size_t n);
  bool is_digit(char c);
}

#endif
