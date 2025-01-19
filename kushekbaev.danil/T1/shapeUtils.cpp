#include "shapeUtils.hpp"
#include <cmath>

namespace kushekbaev
{
  template<std::size_t N>
  void movePoints(std::array<point_t*, N> &points, double dx, double dy)
  {
    for (point_t *point: points)
    {
      point.x += dx;
      point.y += dy;
    }
  }

  template<std::size_t N>
  void scalePoints(std::array<point_t*, N> &points, double scaleCoeff, point_t middle)
  {
    for (point_t* point: points)
    {
      point->x = middle.x + (point->x - middle.x) * scaleCoeff;
      point->y = middle.y + (point->y - middle.y) * scaleCoeff;
    }
  }

  double getLineLength(point_t first, point_t second)
  {
    double width = (first.x - second.x);
    double length = (first.y - second.y);
    return std::sqrt(width * width + length * length);
  }

  double getAreaOfTriangle(point_t first, point_t second, point_t third)
  {
    double side1 = getLineLength(first, second);
    double side2 = getLineLength(second, third);
    double side3 = getLineLength(first, third);
    double p = (side1 + side2 + side3) / 2;
    return std::sqrt(p * (p - side1) * (p - side2) * (p - side3));
  }
}
