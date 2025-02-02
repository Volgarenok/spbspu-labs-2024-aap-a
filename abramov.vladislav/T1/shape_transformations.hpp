#ifndef SHAPE_TRANSFORMATIONS_HPP
#define SHAPE_TRANSFORMATIONS_HPP
#include <cstddef>
#include <iostream>
#include <iomanip>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "complexquad.hpp"
#include "shape.hpp"
#include "composite-shape.hpp"

namespace abramov
{
  void getShapes(std::istream &in, Composite &shapes, point_t &p, double &k, bool &flag);
  Rectangle *makeRectangle(std::istream &in);
  Square *makeSquare(std::istream &in);
  ComplexQuad *makeComplexQuad(std::istream &in);
  void scaleFigure(Shape *s, point_t p, double k);
  void unsafeScaleFigure(Shape *s, point_t p, double k);
  void printAllShapes(std::ostream &out, Composite &shapes, point_t p, double k, size_t i);
}
#endif
