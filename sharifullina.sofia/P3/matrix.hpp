#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <fstream>

namespace sharifullina
{
  std::istream & inputMatrix(std::istream & in, int * t, size_t m, size_t n, size_t & read);
  int countMaxSumMdg(const int * t, size_t m, size_t n);
  size_t countLocMax(const int * t, size_t m, size_t n);
  bool isLocMax(const int * t, size_t n, size_t i, size_t j);
}
#endif
