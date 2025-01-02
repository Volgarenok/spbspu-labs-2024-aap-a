#ifndef SHAPE_ADDON_HPP
#define SHAPE_ADDON_HPP
#include <cstddef>
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"

namespace savintsev
{
  void scaleRelativeTo(Shape * rhs, point_t p, double k);
  void scaleAllRelativeTo(Shape ** rhs, size_t amt, point_t p, double k);
  void printSumAreaAndBorders(std::ostream & out, Shape ** rhs, size_t amt);
  int actWithShpByDesc(char * desc, Shape ** rhs, size_t & amt, point_t & p, double & k);
  void destroyArray(Shape ** rhs, size_t amt);
}

#endif
