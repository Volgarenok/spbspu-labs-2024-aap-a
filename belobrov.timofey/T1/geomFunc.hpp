#ifndef GEOM_FUNC_HPP
#define GEOM_FUNC_HPP
#include <cstddef>
#include "shape.hpp"

namespace belobrov
{
  void deleteShapes(Shape** shapes, size_t count);
  void outputFrameCoordinates(Shape** shapes, size_t count);
  void applyIsoScaling(Shape** shapes, size_t count, const point_t& center, double factor);
  double calculateTotalArea(Shape** shapes, size_t count);
}

#endif
