#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>

namespace karnauhova
{
  bool input_rectangle(std::istream & in, double* x_y, size_t j);
  bool input_triangle(std::istream & in, double* x_y, size_t j);
  bool input_scale(std::istream & in, double* x_y, size_t j);
  void eat_trash(std::istream & in);
}

#endif
