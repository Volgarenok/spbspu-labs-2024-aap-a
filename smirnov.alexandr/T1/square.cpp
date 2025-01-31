#include "square.hpp"
#include <stdexcept>

smirnov::Square::Square(double x, double y, double length):
  lowerLeft{x, y},
  sideLength(length)
{
  if (length <= 0)
  {
    throw std::invalid_argument("Side length must be positive");
  }
}

double smirnov::Square::getArea() const
{
  return sideLength * sideLength;
}

smirnov::rectangle_t smirnov::Square::getFrameRect() const
{
  point_t center = {lowerLeft.x + sideLength / 2, lowerLeft.y + sideLength / 2};
  return {center, sideLength, sideLength};
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
  applyMove(lowerLeft, dx, dy);
}

void smirnov::Square::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Zoom coefficient must be positive");
  }
  point_t center = getFrameRect().pos;
  sideLength *= k;
  applyScale(lowerLeft, center, k);
}
