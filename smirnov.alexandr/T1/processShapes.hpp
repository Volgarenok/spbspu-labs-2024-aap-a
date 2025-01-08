#ifndef PROCESSSHAPES_HPP
#define PROCESSSHAPES_HPP
#include <cstddef>
#include <ostream>
#include "shape.hpp"

namespace smirnov
{
  double sumArea(const Shape * const * const shapes, size_t count);
  void destroyShapes(Shape ** shapes, size_t count);
  void printFrameRect(const Shape * const * const shapes,
      size_t count, std::ostream & out);
  void scaleShapes(Shape ** shapes, size_t count, point_t p, double factor);
}
#endif
