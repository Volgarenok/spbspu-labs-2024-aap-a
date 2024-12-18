#ifndef PROCESSSHAPES_HPP
#define PROCESSSHAPES_HPP
#include <cstddef>
#include "shape.hpp"

namespace smirnov
{
  double sumArea(Shape ** shapes, size_t count);
  void destroyShapes(Shape ** shapes, size_t count);
  void printFrameRect(Shape ** shapes, size_t count);
  void scaleShapes(Shape ** shapes, size_t count, point_t p, double factor);
}
#endif
