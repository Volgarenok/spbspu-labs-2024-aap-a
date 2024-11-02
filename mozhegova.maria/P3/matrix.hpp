#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

namespace mozhegova
{
  bool isNumber(const char * str);
  int ** createMatrix(size_t m, size_t n);
  void destroy(int ** t, size_t m);
  std::istream & inputMatrix(std::istream & in, int ** t, size_t m, size_t n, size_t & read);
  int * convert(int ** t, size_t m, size_t n);
  bool uppTriMtx(int * v, size_t m, size_t n);
}

#endif
