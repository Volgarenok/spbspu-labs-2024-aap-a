#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <istream>

namespace sharifullina
{
  bool isNumber(const shar * str);
  int ** inMatrix(size_t m, size_t n);
  void destroy(int ** t, size_t m);
  std::istream & inputMatrix(std::istream & in, int ** t, size_t m, size_t n, size_t & read);
  
}
#endif
