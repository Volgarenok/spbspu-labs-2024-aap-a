#ifndef INPUT_OUTPUT_HPP
#define INPUT_OUTPUT_HPP
#include <cstddef>
namespace karnauhova
{
  std::istream & input_matrix(std::istream & in, int * t, size_t m, size_t n, size_t & read);
  void output_matrix(std::ostream & out, int * t, size_t m, size_t n);
}
#endif
