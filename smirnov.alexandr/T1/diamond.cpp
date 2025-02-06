#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
smirnov::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  parallelogram()
{
  /*if ((p1.x == p2.x && p1.y == p2.y) && (p1.x == p3.x && p1.y == p3.y))
  {
    throw std::invalid_argument("All three vertices cannot coincide");
  }
  if ((p1.x == p2.x && p1.y == p2.y) || (p1.x == p3.x && p1.y == p3.y)
      || (p2.x == p3.x && p2.y == p3.y))
  {
    throw std::invalid_argument("Two vertices cannot coincide");
  }*/
  if (!((p1.x == p2.x && p2.y == p3.y) || (p1.y == p2.y && p2.x == p3.x)))
  {
    throw std::invalid_argument("Diagonals of the diamond must be parallel to the axes");
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
