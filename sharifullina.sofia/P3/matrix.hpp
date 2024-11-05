#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <istream>
#include <fstream>

namespace sharifullina
{
  bool isNumber(const char * str);
  int ** inMatrix(size_t m, size_t n);
  void destroy(int ** t, size_t m);
  std::istream & inputMatrix(std::istream & in, int ** t, size_t m, size_t n, size_t & read);
  int maxSumOfDiag(const int t, size_t m, size_t n)
}
#endif
