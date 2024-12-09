#ifndef SHAPE_TRANSFORMATIONS_HPP
#define SHAPE_TRANSFORMATIONS_HPP
#include "base-types.hpp"
#include <cstddef>
#include "shape.hpp"

namespace abramov
{
  void printFrameRectCoords(const rectangle_t &r);
  void scaleFigure(Shape *r, point_t p, double k);
  void deleteShapes(Shape **x, size_t i);
}
#endif
