#ifndef INPUT_MATRIX_H
#define INPUT_MATRIX_H
#include <istream>
#include <cstddef>

namespace lanovenko
{
  std::istream& input_matrix(std::istream& in, int* matrix, size_t sizematrix);
}
#endif
