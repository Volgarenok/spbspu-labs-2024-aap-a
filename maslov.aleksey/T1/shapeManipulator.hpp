#ifndef SHAPE_MANIPULATOR_HPP
#define SHAPE_MANIPULATOR_HPP

#include <iostream>
#include "composite-shape.hpp"

namespace maslov
{
  double getSumArea(const CompositeShape &);
  void scaleShapes(CompositeShape &, point_t coordinate, double factor);
  void printData(std::ostream &, const CompositeShape &);
  void destroyShapes(CompositeShape &);
}

#endif
