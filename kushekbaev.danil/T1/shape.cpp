#include "shape.hpp"
#include <cmath>

namespace kushekbaev
{
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

  void Shape::scaleEverything(point_t scalePoint, double scaleCoeff)
  {
    point_t beforeScale = getFrameRect().pos;
    move(scalePoint);
    point_t afterScale = getFrameRect().pos;
    point_t vector = { (afterScale.x - beforeScale.x) * scaleCoeff, (afterScale.y - beforeScale.y) * scaleCoeff };
    scale(scaleCoeff);
    move(-vector.x, -vector.y);
  }
}
