#ifndef OUTPUT_MATRIX_H
#define OUTPUT_MATRIX_H

#include <ostream>
#include <cstddef>
#include <cmath>

namespace timofeev
{
  void check_diag(std::ostream& out, int* matrix, size_t strk, size_t stl);
}
#endif
