#ifndef MATRIXFUNC_H
#define MATRIXFUNC_H

#include <istream>

namespace averenkov {
  std::istream& input_matrix(std::istream& in, int** t, size_t rows, size_t cols, size_t& read);
  size_t num_col_lsr(int** t, size_t rows, size_t cols);
  void destroy(int** t, size_t rows);
  void output_matrix(std::ostream& out, int** t, size_t rows, size_t cols);
}

#endif
