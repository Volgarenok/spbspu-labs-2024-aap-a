#ifndef INPUT_OUPUT_MATRIX_HPP
#define INPUT_OUPUT_MATRIX_HPP
#include <cstddef>
#include <fstream>

namespace brevnov
{
  int input_matrix(std::istream & in, int * t, size_t m, size_t n);
  void output_matrix(std::ostream & out, const int * t, size_t m, size_t n);
}
#endif
