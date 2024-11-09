#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iosfwd>
#include <fstream>

namespace brevnov
{
  int input_matrix(std::ifstream & in, int * t, size_t m, size_t n);
}
#endif
