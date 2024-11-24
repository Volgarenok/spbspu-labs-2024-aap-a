#ifndef INPUT_OUTPUT_HPP
#define INPUT_OUTPUT_HPP
#include <cstddef>
#include <fstream>

namespace karnauhova
{
  std::ifstream & input_matrix(std::ifstream & in, int * t, size_t m, size_t n, size_t & read);
  void output_matrix(std::ofstream & out, const float * t, size_t m, size_t n);
}
#endif
