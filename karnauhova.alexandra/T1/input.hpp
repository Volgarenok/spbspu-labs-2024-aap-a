#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>

namespace karnauhova
{
  bool input_rectangle(std::istream & in, double* x_y, size_t j);
  bool input_triangle(std::istream & in, double* x_y, size_t j);
  bool input_scale(std::istream & in, double* x_y, size_t j);
  size_t input_polygon(std::istream & in, double* polygon, size_t count_polygon);
  void eat_trash(std::istream & in);
}

#endif
