#ifndef SHAPE_MANIPULATOR_HPP
#define SHAPE_MANIPULATOR_HPP

#include <cstddef>
#include "shape.hpp"

namespace maslov
{
  double getSumArea(const Shape * const * const shapes, const size_t count);
  void scaleShapes(Shape ** shapes, const size_t count,
      const point_t scaleCoordinate, const double scaleFactor);
  void printCoordinates(const Shape * const * const shapes, const size_t count);
  void destroyShapes(Shape ** shapes, const size_t count);
}

#endif
