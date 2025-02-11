#ifndef ACTIONSHAPES_HPP
#define ACTIONSHAPES_HPP

#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace sharifullina
{
  double getSumArea(const Shape * const * shapes, size_t n);
  void printCoorRect(std::ostream & out, const Shape * const * shapes, size_t n);
  void scaleOfShapes(Shape ** shapes, size_t n, point_t p, double k);
  void destroyShapes(Shape ** shapes, size_t n);
}

#endif
