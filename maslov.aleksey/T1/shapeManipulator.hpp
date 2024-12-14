#ifndef SHAPE_MANIPULATOR_HPP
#define SHAPE_MANIPULATOR_HPP

#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>

namespace maslov
{
  double getSumArea(Shape** shapes, size_t count);
  void scaleShapes(maslov::Shape** shapes, size_t count, point_t scaleCoor, double scaleFactor);
  void printCoor(Shape** shapes, size_t count);
}

#endif
