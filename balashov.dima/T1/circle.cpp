#include "circle.hpp"
#include <cmath>
#include <stdexcept>

balashov::Circle::Circle(point_t center, double radius)
{
  centerPoint = center;
  radiusCircle = radius;
}

double balashov::Circle::getArea() const
{
  const double pi = 3.14;
  return pi * pow(radiusCircle, 2);
}

balashov::rectangle_t balashov::Circle::getFrameRect() const
{
  rectangle_t point;
  point.width = radiusCircle * 2;
  point.height = radiusCircle * 2;
  point.pos = centerPoint;
  return point;
}

void balashov::Circle::move(point_t target)
{
  centerPoint = target;
}

void balashov::Circle::move(double x, double y)
{
  centerPoint.x += x;
  centerPoint.y += y;
}


void balashov::Circle::scale(double scaleCoefficient)
{
  radiusCircle *= scaleCoefficient;
}
