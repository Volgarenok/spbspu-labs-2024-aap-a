#ifndef SHAPES_UTILS_HPP
#define SHAPES_UTILS_HPP

#include <iostream>
#include "composite-shape.hpp"

namespace guseynov
{
  double getSumArea(const CompositeShape &);
  void scaleShapes(CompositeShape &, point_t coordinate, double factor);
  void printData(std::ostream &, const CompositeShape &);
  void destroyShapes(CompositeShape &);
}

#endif
