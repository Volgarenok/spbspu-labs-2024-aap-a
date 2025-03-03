#ifndef SHAPE_CHANGER_HPP
#define SHAPE_CHANGER_HPP

#include <iostream>
#include "shape.hpp"

namespace balashov
{
  void printShapeInfo(Shape** shapes, size_t count);
  void scaling(Shape** shapes, size_t count, point_t point, double scalingFactor);
}

#endif
