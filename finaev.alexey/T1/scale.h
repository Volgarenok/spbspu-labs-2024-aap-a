#ifndef SCALE_H
#define SCALE_H

#include "shape.h"
#include <cstddef>

namespace finaev
{
  void scale(Shape** shapes, size_t size, point_t scaleCenter, double k);
}

#endif
