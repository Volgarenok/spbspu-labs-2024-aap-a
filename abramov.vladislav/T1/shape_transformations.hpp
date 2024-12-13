#ifndef SHAPE_TRANSFORMATIONS_HPP
#define SHAPE_TRANSFORMATIONS_HPP
#include "base-types.hpp"
#include <cstddef>
#include <iostream>
#include "rectangle.hpp"
#include "square.hpp"
#include "complexquad.hpp"
#include "shape.hpp"

namespace abramov
{
  void getShapes(std::istream &in, Shape **shapes, size_t &i, double &x, double &y, double &k, bool &flag);
  void printFrameRectCoords(const rectangle_t &r);
  void scaleFigure(Shape *r, point_t p, double k);
  void deleteShapes(Shape **x, size_t i);
}
#endif
