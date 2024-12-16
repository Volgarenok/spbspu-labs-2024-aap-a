#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <string>
#include <iostream>
#include "shape.hpp"
namespace karnauhova
{
  void output(std::ostream & out, double* all_points, double* polygon, std::string* names, size_t c_points, size_t c_shape);
  void scale_point(Shape& object, point_t t, double k);
}

#endif
