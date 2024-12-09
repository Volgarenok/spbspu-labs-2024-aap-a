#ifndef SHAPE_UTILS_HPP
#define SHAPE_UTILS_HPP

#include <cstddef>
#include "shape.hpp"

namespace kizhin {
  Shape* createShape(const char*, const double*);
  void scaleShapes(Shape* const*, size_t, const double*);
  double computeTotalArea(const Shape* const*, size_t size);
}

#endif
