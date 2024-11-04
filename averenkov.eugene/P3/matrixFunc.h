#ifndef MATRIXFUNC_H
#define MATRIXFUNC_H

#include <istream>

namespace averenkov {
  std::istream& input_matrix(std::istream& in, int* matrix, size_t m, size_t n, size_t& read);
  size_t num_col_lsr(int* matrix, size_t m, size_t n);
  void output_matrix(std::ostream& out, int* matrix, size_t m, size_t n);
}

#endif
