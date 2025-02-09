#ifndef MATRIX_FUNCTIONS_HPP
#define MATRIX_FUNCTIONS_HPP
#include <iostream>

namespace dirti
{
  void input_matrix(std::istream & in, int * t, size_t m, size_t n, size_t & read);
  int local_min(const int * matrix, size_t m, size_t n);
  bool matrix_checking(const int * matrix, size_t m, size_t n);
}

#endif
