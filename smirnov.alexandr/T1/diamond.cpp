#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
smirnov::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  parallelogram()
{
  if ((p1.x == p2.x && p1.y == p2.y) ||
      (p1.x == p3.x && p1.y == p3.y) ||
      (p2.x == p3.x && p2.y == p3.y))
  {
    throw std::invalid_argument("Points must be unique");
  }

  if (!(p1.y == p3.y))
  {
    throw std::invalid_argument("Diagonals must be parallel to the coordinate axes");
  }
  point_t center = {p2.x, p1.y};
  if (center.x == p1.x || center.y != p1.y)
  {
    throw std::invalid_argument("Diagonals must intersect at their midpoints");
  }
  parallelogram = Parallelogram{p1, p2, p3};
}

double smirnov::Diamond::getArea() const
{
  return parallelogram.getArea();
}

smirnov::rectangle_t smirnov::Diamond::getFrameRect() const
{
  return parallelogram.getFrameRect();
}

void smirnov::Diamond::move(point_t newPos)
{
  return parallelogram.move(newPos);
}

void smirnov::Diamond::move(double dx, double dy)
{
  parallelogram.move(dx, dy);
}

void smirnov::Diamond::scale(double k)
{
  parallelogram.scale(k);
}
