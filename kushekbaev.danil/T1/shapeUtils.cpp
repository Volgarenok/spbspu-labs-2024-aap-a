#include "shapeUtils.hpp"
#include <cmath>

namespace kushekbaev
{
  void movePoints(point_t** points, size_t size, double dx, double dy)
  {
    for (size_t i = 0; i < size; i++)
    {
      points[i]->x += dx;
      points[i]->y += dy;
    }
  }

  void scalePoints(point_t** points, size_t size, double scaleCoeff, point_t middle)
  {
    for (size_t i = 0; i < size; i++)
    {
      points[i]->x = middle.x + scaleCoeff * (points[i]->x - middle.x);
      points[i]->y = middle.y + scaleCoeff * (points[i]->y - middle.y);
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
