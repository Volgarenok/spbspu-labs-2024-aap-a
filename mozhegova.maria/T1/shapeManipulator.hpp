#ifndef SHAPEMANIPULATOR_HPP
#define SHAPEMANIPULATOR_HPP

#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace mozhegova
{
  double sumArea(Shape ** shapes, size_t n);
  void printCoorRect(Shape ** shapes, size_t n);
  void scaleShapes(Shape ** shapes, size_t n, point_t p, double k);
  double * getNum(char * tok, size_t &length);
  void destroy(Shape ** shapes, size_t n);
}

#endif
