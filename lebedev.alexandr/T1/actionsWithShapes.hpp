#ifndef ACTIONSWITHSHAPES_HPP
#define ACTIONSWITHSHAPES_HPP
#include "shape.hpp"

namespace lebedev
{
  double getSumArea(const Shape** shps, size_t count);
  void scaleForShapes(Shape** shps, size_t count, point_t scalePoint, double k);
  void printFrameCoordinates(const Shape** shps, size_t count, std::ostream& output);
}
#endif
