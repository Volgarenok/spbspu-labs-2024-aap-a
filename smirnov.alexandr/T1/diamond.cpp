#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
smirnov::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  parallelogram()
{
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
