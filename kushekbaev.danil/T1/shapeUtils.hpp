#ifndef SHAPEUTILS_HPP
#define SHAPEUTILS_HPP

#include <cstddef>
#include "base-types.hpp"

namespace kushekbaev
{
  bool isTriangle(point_t first, point_t second, point_t third);
  bool isPointInsideTriangle(point_t first, point_t second, point_t third, point_t last);
  void movePoints(point_t** points, size_t size, double dx, double dy);
  void scalePoints(point_t** points, size_t size, double scaleCoeff, point_t mid);
  double getLineLength(point_t first, point_t second);
  double getAreaOfTriangle(point_t first, point_t second, point_t third);
}

#endif
