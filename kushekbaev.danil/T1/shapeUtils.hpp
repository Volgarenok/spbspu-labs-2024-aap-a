#ifndef SHAPEUTILS_HPP
#define SHAPEUTILS_HPP

#include "base-types.hpp"
#include <array>

namespace kushekbaev
{
  template<std::size_t N>
  void movePoints(std::array<point_t*, N> &points, double dx, double dy)
  {
    for (point_t* point : points)
    {
      point->x += dx;
      point->y += dy;
    }
  }
  template<std::size_t N>
  void scalePoints(std::array<point_t*, N> &points, const double scaleCoeff, const point_t middle)
  {
    for (point_t* point : points)
    {
      point->x = middle.x + scaleCoeff * (point->x - middle.x);
      point->y = middle.y + scaleCoeff * (point->y - middle.y);
    }
  }
  double getLineLength(const point_t first, const point_t second);
  double getAreaOfTriangle(const point_t first, const point_t second, const point_t third);
}

#endif
