#ifndef GEOM_FUNC_HPP
#define GEOM_FUNC_HPP
#include <cstddef>
#include "shape.hpp"

namespace belobrov
{
  void deleteShapes(Shape** shapes, size_t count);
  void outputFrameCoordinates(Shape** shapes, size_t count);
  void applyIsoScaling(Shape** shapes, size_t count, const point_t& center, double k);
  double calculateTotalArea(Shape** shapes, size_t count);
  bool isCorrectTriangle(point_t v1, point_t v2, point_t v3);
  double calculateTriangleArea(point_t v1, point_t v2, point_t v3);
  bool isPointInTriangle(point_t v1, point_t v2, point_t v3, point_t point);
}

#endif
