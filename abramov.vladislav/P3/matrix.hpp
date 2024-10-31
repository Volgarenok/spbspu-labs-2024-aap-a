#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <fstream>

namespace abramov
{
  std::istream &input_matrix(std::istream &in, int *mtx, size_t m, size_t n, size_t &read);
  void output_matrix(std::ostream &out, int *mtx, size_t m, size_t n);
}
#endif
