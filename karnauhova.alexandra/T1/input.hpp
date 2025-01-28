#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
namespace karnauhova
{
  bool input_rectangle(std::istream & in, Shape** shaps, size_t count_shaps);
  bool input_triangle(std::istream & in, Shape** shaps, size_t count_shaps);
  bool input_scale(std::istream & in, point_t& point, double& k);
  bool input_polygon(std::istream & in, Shape** shaps, size_t count_shaps);
  bool fabric_input(std::istream & in, Shape** shaps, size_t& count_error, point_t& point, double& k, size_t& count_shape);
  void eat_trash(std::istream & in);
  point_t* expansion(point_t* a, size_t old, size_t dl);
}

#endif
