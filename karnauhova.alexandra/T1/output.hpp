#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <string>
#include <iostream>
#include "shape.hpp"
namespace karnauhova
{
  void output(std::ostream & out, Shape** shaps, point_t point, double k, double c_shape);
  void scale_point(Shape& object, point_t t, double k);
}

#endif
