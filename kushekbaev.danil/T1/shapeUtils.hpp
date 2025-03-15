#ifndef SHAPEUTILS_HPP
#define SHAPEUTILS_HPP

#include <cstddef>
#include "base-types.hpp"

namespace kushekbaev
{
  bool isTriangle(point_t first, point_t second, point_t third);
  bool isPointInsideTriangle(point_t first, point_t second, point_t third, point_t last);
  void movePoints(point_t** points, const size_t size, const double dx, const double dy);
  void scalePoints(point_t** points, const size_t size, const double scaleCoeff, const point_t mid);
  double getLineLength(point_t first, point_t second);
  double getAreaOfTriangle(point_t first, point_t second, point_t third);
}

#endif
