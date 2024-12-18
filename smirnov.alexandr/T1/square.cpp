#include "square.hpp"

smirnov::Square::Square(double x, double y, double length)
{
  lowerLeft = {x, y};
  sideLength = length;
}

double smirnov::Square::getArea() const
{
  return sideLength * sideLength;
}

smirnov::rectangle_t smirnov::Square::getFrameRect() const
{
  point_t center;
  center.x = lowerLeft.x + sideLength / 2;
  center.y = lowerLeft.y + sideLength / 2;
  rectangle_t frameRect;
  frameRect.pos = center;
  frameRect.width = sideLength;
  frameRect.height = sideLength;
  return frameRect;
}

void smirnov::Square::move(point_t newPos)
{
  point_t currentPos = getFrameRect().pos;
  double dx = newPos.x - currentPos.x;
  double dy = newPos.y - currentPos.y;
  move(dx, dy);
}

void smirnov::Square::move(double dx, double dy)
{
  lowerLeft.x += dx;
  lowerLeft.y += dy;
}

void smirnov::Square::scale(double k)
{
  point_t center = getFrameRect().pos;
  sideLength *= k;
  lowerLeft.x = center.x - sideLength / 2;
  lowerLeft.y = center.y - sideLength / 2;
}
