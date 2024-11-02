#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <fstream>

namespace abramov
{
  std::istream &input_Matrix(std::istream &in, int *mtx, size_t m, size_t n, size_t &read);
  int *toSquare(int *mtx, size_t m, size_t n, size_t &count);
  void transform_Matrix(int *mtx, size_t count);
  void output_Matrix(std::ostream &out, int *mtx, size_t m);
}
#endif
