#ifndef SHAPE_TRANSFORMATIONS_HPP
#define SHAPE_TRANSFORMATIONS_HPP
#include "base-types.hpp"
#include <cstddef>
#include <iostream>
#include <iomanip>
#include "rectangle.hpp"
#include "square.hpp"
#include "complexquad.hpp"
#include "shape.hpp"

namespace abramov
{
  void getShapes(std::istream &in, Shape **shapes, size_t &i, double &x, double &y, double &k, bool &flag);
  void printShapes(std::ostream &out, Shape **shapes, rectangle_t *rects, size_t i, double &x, double & y, double k);
  void printFrameRectCoords(const rectangle_t &r);
  void scaleFigure(Shape *r, point_t p, double k);
  void deleteShapes(Shape **x, size_t i);
}
#endif
