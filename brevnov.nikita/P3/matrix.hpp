#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>

namespace brevnov
{
  int input_matrix(std::ifstream & in, int * t, size_t m, size_t n);
  int * alloc(size_t m, size_t n);
  int osed_fun(const int * t, size_t m, size_t n);
  size_t find_index_min(const int * t, size_t n, size_t i);
  size_t find_index_max(const int * t, size_t m, size_t n, int min_mem);
}
#endif
