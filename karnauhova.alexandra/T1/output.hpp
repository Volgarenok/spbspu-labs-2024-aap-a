#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <string>
#include <iostream>
#include "shape.hpp"
#include "compositeShape.hpp"
namespace karnauhova
{
  void output(std::ostream & out, CompositeShape& shaps, point_t point, double k);
  void scale_point(Shape* object, point_t t, double k);
}

#endif
