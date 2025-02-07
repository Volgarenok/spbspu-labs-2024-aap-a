#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include <string>
#include "shape.hpp"
#include "base-types.hpp"
#include "compositeShape.hpp"
namespace karnauhova
{
  void input_points(std::istream & in, point_t* point, size_t count);
  void input_rectangle(std::istream & in, CompositeShape& shaps);
  void input_triangle(std::istream & in, CompositeShape& shaps);
  void input_scale(std::istream & in, point_t& point, double& k);
  void input_polygon(std::istream & in, CompositeShape& shaps);
  void fabric_input(std::istream & in, CompositeShape& shaps, point_t& point, double& k, std::string name);
  point_t* expand(point_t* a, size_t old, size_t dl);
}

#endif
