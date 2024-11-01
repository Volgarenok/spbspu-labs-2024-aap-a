#ifndef MATRIX_FUNCS_H
#define MATRIX_FUNCS_H
#include <cstddef>
#include <iostream>

namespace demehin
{
  int* alloc(size_t k, int c);
  std::istream & input_matrix(std::istream & in, int* t, size_t k, size_t & read);
}
#endif
