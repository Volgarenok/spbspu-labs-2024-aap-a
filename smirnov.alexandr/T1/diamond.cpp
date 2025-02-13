#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
smirnov::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  parallelogram_(p1, p2, p3)
{
  parallelogram_ = Parallelogram{p1, p2, p3};
  if (!(p1.y == p3.y))
  {
    throw std::invalid_argument("Diagonals must be parallel to the coordinate axes");
  }
  point_t center = {p2.x, p1.y};
  if (center.x == p1.x || center.y != p1.y)
  {
    throw std::invalid_argument("Diagonals must intersect at their midpoints");
  }
}

double smirnov::Diamond::getArea() const
{
  return parallelogram_.getArea();
}

smirnov::rectangle_t smirnov::Diamond::getFrameRect() const
{
  return parallelogram_.getFrameRect();
}

void smirnov::Diamond::move(point_t newPos)
{
  return parallelogram_.move(newPos);
}

void smirnov::Diamond::move(double dx, double dy)
{
  parallelogram_.move(dx, dy);
}

void smirnov::Diamond::scale(double k)
{
  parallelogram_.scale(k);
}
