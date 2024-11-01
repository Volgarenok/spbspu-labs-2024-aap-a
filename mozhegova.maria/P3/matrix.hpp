#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

namespace mozhegova
{
  bool isNumber(const char * str);
  int ** createMatrix(size_t m, size_t n);
  void destroy(int ** t, size_t m);
}

#endif