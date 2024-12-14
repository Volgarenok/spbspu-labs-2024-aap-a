#include "rectangle.hpp"

smirnov::Rectangle::Rectangle(double x1, double y1, double x2, double y2)
{
  lowerLeft.x = x1;
  lowerLeft.y = y1;
  upperRight.x = x2;
  upperRight.y = y2;
}
double smirnov::Rectangle::getArea() const
{
  return (upperRight.x - lowerLeft.x) * (upperRight.y - lowerLeft.y);
}

