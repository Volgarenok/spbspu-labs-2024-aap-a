#ifndef OUTPUT_MATRIX_H
#define OUTPUT_MATRIX_H

#include <ostream>
#include <cstddef>

namespace finaev
{
  void output_matrix(std::ostream & out, int *matrix, size_t strk, size_t stl);
}

#endif
