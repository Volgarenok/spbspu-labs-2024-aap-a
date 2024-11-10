#ifndef INPUT_OUPUT_MATRIX_HPP
#define INPUT_OUPUT_MATRIX_HPP
#include <cstddef>
#include <fstream>

namespace brevnov
{
  int input_matrix(std::ifstream & in, int * t, size_t m, size_t n);
  void output_matrix(std::ofstream & out, int * t, size_t m, size_t n);
}
#endif
