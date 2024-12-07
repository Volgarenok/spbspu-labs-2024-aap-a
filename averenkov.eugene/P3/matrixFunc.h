#ifndef MATRIXFUNC_H
#define MATRIXFUNC_H
#include <istream>

namespace averenkov
{
  std::istream& input_matrix(std::istream& in, int* t, size_t m, size_t n, size_t& read);
  int max_sum_sdg(const int* t, size_t m, size_t n);
  size_t num_col_lsr(const int* t, size_t m, size_t n);
  void output_matrix(std::ostream& out, const int* t, size_t m, size_t n);
  void output_answer(std::ostream& out, const int* t, size_t m, size_t n);
}

#endif
