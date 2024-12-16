#include "diamond.hpp"
#include <stdexcept>

smirnov::Diamond::Diamond(double x, double y, double d1, double d2)
  : center{x, y}, diagonal1(d1), diagonal2(d2)
{
}

double smirnov::Diamond::getArea() const
{
  return (diagonal1 * diagonal2) / 2;
}

smirnov::rectangle_t smirnov::Diamond::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.pos = center;
  frameRect.width = diagonal1;
  frameRect.height = diagonal2;
  return frameRect;
}

void smirnov::Diamond::move(point_t newPos)
{
  center = newPos;
}

void smirnov::Diamond::move(double dx, double dy)
{
  center.x += dx;
  center.y += dy;
}

void smirnov::Diamond::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("The zoom factor must be positive.");
  }
  diagonal1 *= k;
  diagonal2 *= k;
}
