#include "square.hpp"
#include <stdexcept>

smirnov::Square::Square(double x, double y, double sideLength)
  : lowerLeft{x, y}, side(sideLength)
{
}

double smirnov::Square::getArea() const
{
  return side * side;
}

smirnov::rectangle_t smirnov::Square::getFrameRect() const
{
  point_t center;
  center.x = lowerLeft.x + side / 2;
  center.y = lowerLeft.y + side / 2;
  rectangle_t frameRect;
  frameRect.pos = center;
  frameRect.width = side;
  frameRect.height = side;
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
  if (k <= 0)
  {
    throw std::invalid_argument("The zoom factor must be positive.");
  }
  point_t center = getFrameRect().pos;
  lowerLeft.x = (lowerLeft.x - center.x) * k + center.x;
  lowerLeft.x = (lowerLeft.x - center.x) * k + center.x;
  side *= k;
}
