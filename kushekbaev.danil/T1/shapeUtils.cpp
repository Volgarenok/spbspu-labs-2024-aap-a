#include "shapeUtils.hpp"
#include <cmath>

namespace kushekbaev
{
  bool isTriangle(point_t first, point_t second, point_t third)
  {
    double side1 = getLineLength(first, second);
    double side2 = getLineLength(second, third);
    double side3 = getLineLength(first, third);
    return((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1));
  }

  bool isPointInsideTriangle(point_t first, point_t second, point_t third, point_t last)
  {
    double fstcheck = (first.x - last.x) * (second.y - first.y) - (second.x - first.x) * (first.y - last.y);
    double sndcheck = (second.x - last.x) * (third.y - second.y) - (third.x - second.x) * (second.y - last.y);
    double trdcheck = (third.x - last.x) * (first.y - third.y) - (first.x - third.x) * (third.y - last.y);
    return ((fstcheck > 0 && sndcheck > 0 && trdcheck > 0) || (fstcheck < 0 && sndcheck < 0 && trdcheck < 0));
  }

  void movePoints(point_t** points, size_t size, double dx, double dy)
  {
    for (size_t i = 0; i < size; i++)
    {
      points[i]->x += dx;
      points[i]->y += dy;
    }
  }

  void scalePoints(point_t** points, size_t size, double scaleCoeff, point_t mid)
  {
    for (size_t i = 0; i < size; i++)
    {
      points[i]->x = mid.x + scaleCoeff * (points[i]->x - mid.x);
      points[i]->y = mid.y + scaleCoeff * (points[i]->y - mid.y);
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
