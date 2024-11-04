#ifndef INPUT_MATRIX_H
#define INPUT_MATRIX_H

#include <istream>
#include <cstddef>

namespace finaev
{
  std::istream& input_matrix(std::istream & in, int *matrix, size_t size_matrix);
}

#endif
