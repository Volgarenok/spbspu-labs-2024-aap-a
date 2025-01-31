#ifndef SHAPE_MANIPULATOR_HPP
#define SHAPE_MANIPULATOR_HPP

#include <iostream>
#include "composite-shape.hpp"

namespace maslov
{
  double getSumArea(const CompositeShape &);
  void scaleShapes(CompositeShape &, const point_t coordinate, const double factor);
  void printCoordinates(std::ostream &, const CompositeShape &);
  void destroyShapes(CompositeShape &);
}

#endif
