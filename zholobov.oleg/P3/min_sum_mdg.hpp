#ifndef MIN_SUM_MDG_H
#define MIN_SUM_MDG_H

#include <cstddef>
#include <istream>

namespace zholobov {
  void read_matrix(std::istream& input_stream, int* matrix, size_t elements_to_read);
  int calc_min_sum_mdg(const int* matrix, size_t rows, size_t cols);
}

#endif
