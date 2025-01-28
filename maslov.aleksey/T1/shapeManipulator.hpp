#ifndef SHAPE_MANIPULATOR_HPP
#define SHAPE_MANIPULATOR_HPP

#include <cstddef>
#include <iostream>
#include "composite-shape.hpp"

namespace maslov
{
  double getSumArea(const CompositeShape & compositeShape);
  void scaleShapes(CompositeShape & compositeShape,
      const point_t scaleCoordinate, const double scaleFactor);
  void printCoordinates(std::ostream & out,
      const CompositeShape & compositeShape);
  void destroyShapes(CompositeShape & compositeShape);
}

#endif
