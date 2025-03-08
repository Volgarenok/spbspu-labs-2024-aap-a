#ifndef SCALE_HPP
#define SCALE_HPP

#include <cstddef>
#include "shape.hpp"

namespace finaev
{
  void scale(Shape** shapes, size_t size, point_t scaleCenter, double k);
}

#endif
