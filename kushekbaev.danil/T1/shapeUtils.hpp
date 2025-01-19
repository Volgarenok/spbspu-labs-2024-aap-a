#ifndef SHAPEUTILS_HPP
#define SHAPEUTILS_HPP

#include <cstddef>
#include "base-types.hpp"

namespace kushekbaev
{
  void movePoints(point_t** points, const size_t size, const double dx, const double dy);
  void scalePoints(point_t** points, const size_t size, const double scaleCoeff, const point_t middle);
  double getLineLength(const point_t first, const point_t second);
  double getAreaOfTriangle(const point_t first, const point_t second, const point_t third);
}

#endif
