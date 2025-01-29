#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
#include "compositeShape.hpp"
namespace karnauhova
{
  bool input_rectangle(std::istream & in, CompositeShape& shaps);
  bool input_triangle(std::istream & in, CompositeShape& shaps);
  bool input_scale(std::istream & in, point_t& point, double& k);
  bool input_polygon(std::istream & in, CompositeShape& shaps);
  bool fabric_input(std::istream & in, CompositeShape& shaps, size_t& count_error, point_t& point, double& k);
  point_t* expansion(point_t* a, size_t old, size_t dl);
}

#endif
