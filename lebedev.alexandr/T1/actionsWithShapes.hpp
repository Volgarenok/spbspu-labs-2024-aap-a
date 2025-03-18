#ifndef ACTIONSWITHSHAPES_HPP
#define ACTIONSWITHSHAPES_HPP
#include <ostream>
#include "shape.hpp"

namespace lebedev
{
  double getSumArea(Shape** shps, size_t count);
  void scaleForShapes(Shape** shps, size_t count, point_t scalePoint, double k);
  void printFrameCoordinates(const Shape* const* shps, size_t count, std::ostream& output);
  void deleteShapePtr(Shape** shps, size_t count);
}
#endif
