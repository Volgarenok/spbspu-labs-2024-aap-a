#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <istream>

namespace ivanova
{
  std::istream & input_matrix(std::istream & in, int * t, size_t m, size_t n, size_t & read);
  size_t num_col_lsr(const int * t, size_t m, size_t n);
  size_t min_sum_mdg(const int * t, size_t m, size_t n);
}

#endif
