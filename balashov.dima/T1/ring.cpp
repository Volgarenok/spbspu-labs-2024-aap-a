#include "ring.hpp"
#include <cmath>
#include <stdexcept>

balashov::Ring::Ring(point_t center, double radiusIn, double radiusOut)
{
  centerPoint = center;
  innerRadius = radiusIn;
  outerRadius = radiusOut;
}

double balashov::Ring::getArea() const
{
  double innerArea = 3.14* pow(innerRadius, 2);
  double outerArea = 3.14 * pow(outerRadius, 2);
  return outerArea - innerArea;
}

balashov::rectangle_t balashov::Ring::getFrameRect() const
{
  rectangle_t circumscribed;
  circumscribed.width = outerRadius * 2;
  circumscribed.height = outerRadius * 2;
  circumscribed.pos = centerPoint;

  return circumscribed;
}

void balashov::Ring::move(point_t target)
{
  centerPoint = target;
}

void balashov::Ring::move(double x, double y)
{
  centerPoint.x += x;
  centerPoint.y += y;
}

void balashov::Ring::scale(double scaleCoefficient)
{
  innerRadius *= scaleCoefficient;
  outerRadius *= scaleCoefficient;
}
