#ifndef OUTPUT_MATRIX_H
#define OUTPUT_MATRIX_H
#include <ostream>
#include <cstddef>

namespace lanovenko
{
  void output_matrix(std::ostream & out, int *matrix, size_t rows, size_t cols);
}
#endif
