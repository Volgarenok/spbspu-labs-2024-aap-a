#ifndef SHAPE_MANIPULATOR_HPP
#define SHAPE_MANIPULATOR_HPP

#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace maslov
{
  double getSumArea(Shape ** shapes, size_t count);
  void scaleShapes(Shape ** shapes, size_t count,
      point_t scaleCoordinate, double scaleFactor);
  void printCoordinates(Shape ** shapes, size_t count);
  void destroyShapes(Shape ** shapes, size_t count);
}

#endif
