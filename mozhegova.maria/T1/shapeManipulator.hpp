#ifndef SHAPEMANIPULATOR_HPP
#define SHAPEMANIPULATOR_HPP

#include <iostream>
#include "shape.hpp"

namespace mozhegova
{
  double getSumArea(const Shape * const * shapes, size_t n);
  void printCoorRect(std::ostream & out, const Shape * const * shapes, size_t n);
  void scaleShapes(Shape ** shapes, size_t n, point_t p, double k);
  void destroy(Shape ** shapes, size_t n);
}

#endif
