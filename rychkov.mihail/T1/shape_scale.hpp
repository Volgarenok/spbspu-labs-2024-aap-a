#ifndef SHAPE_SCALE_HPP
#define SHAPE_SCALE_HPP

#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace rychkov
{
  void scale(Shape* shape, double coef, point_t scaleCenter);
  void scale(Shape** shapes, size_t size, double coef, point_t scaleCenter);
}

#endif
