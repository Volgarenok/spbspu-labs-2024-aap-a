#ifndef SHAPEUTILS_HPP
#define SHAPEUTILS_HPP

#include "base-types.hpp"
#include <array>

namespace kushekbaev
{
  template<std::size_t N>
  void movePoints(std::array<point_t*, N> &points, const double dx, const double dy);
  void scalePoints(std::array<point_t*, N> &points, const double scaleCoeff, const point_t middle);
  double getLineLength(const point_t first, const point_t second);
  double getAreaOfTriangle(const point_t first, const point_t second, const point_t third);
}

#endif
