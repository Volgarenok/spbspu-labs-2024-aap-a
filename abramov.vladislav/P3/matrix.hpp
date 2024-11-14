#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <fstream>

namespace abramov
{
  std::istream &inputMatrix(std::istream &in, int *mtx, size_t m, size_t n, size_t &read);
  int *toSquare(int *mtx, size_t m, size_t n, size_t &count);
  void transformMatrix(int *mtx, size_t count);
  void outputMatrix(std::ostream &out, const int *mtx, size_t m);
}
#endif
