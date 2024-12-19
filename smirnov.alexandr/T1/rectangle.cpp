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

smirnov::rectangle_t smirnov::Rectangle::getFrameRect() const
{
  point_t center;
  center.x = (lowerLeft.x + upperRight.x) / 2;
  center.y = (lowerLeft.y + upperRight.y) / 2;
  rectangle_t frameRect;
  frameRect.pos = center;
  frameRect.width = upperRight.x - lowerLeft.x;
  frameRect.height = upperRight.y - lowerLeft.y;
  return frameRect;
}

void smirnov::Rectangle::move(point_t newPos)
{
  point_t currentPos = getFrameRect().pos;
  double dx = newPos.x - currentPos.x;
  double dy = newPos.y - currentPos.y;
  move(dx, dy);
}

void smirnov::Rectangle::move(double dx, double dy)
{
  lowerLeft.x += dx;
  lowerLeft.y += dy;
  upperRight.x += dx;
  upperRight.y += dy;
}

void smirnov::Rectangle::scale(double k)
{
  point_t center = getFrameRect().pos;
  lowerLeft.x = (lowerLeft.x - center.x) * k + center.x;
  lowerLeft.y = (lowerLeft.y - center.y) * k + center.y;
  upperRight.x = (upperRight.x - center.x) * k + center.x;
  upperRight.y = (upperRight.y - center.y) * k + center.y;
}
