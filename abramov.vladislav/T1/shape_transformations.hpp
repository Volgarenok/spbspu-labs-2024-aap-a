#ifndef SHAPE_TRANSFORMATIONS_HPP
#define SHAPE_TRANSFORMATIONS_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace abramov
{
  void printFrameRectCoords(const rectangle_t &r);
  void scaleFigure(Shape *r, point_t p, double k);
}
#endif
