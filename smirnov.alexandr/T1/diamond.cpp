#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

smirnov::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  parallelogram_(p1, p2, p3)
{
  point_t center;
  double dx = 0.0, dy = 0.0;
  if ((p1.x == p2.x) && ((p1.y == p3.y) || (p2.y == p3.y)))
  {
    center = {p1.x, p3.y};
    dx = std::abs(center.x - p3.x) * 2;
    dy = std::abs(p1.y - p2.y) * 2;
  }
  else if ((p1.x == p3.x) && ((p1.y == p2.y) || (p2.y == p3.y)))
  {
    center = {p3.x, p2.y};
    dx = std::abs(center.x - p2.x) * 2;
    dy = std::abs(p3.y - p1.y) * 2;
  }
  else if ((p2.x == p3.x) && ((p1.y == p2.y) || (p1.y == p3.y)))
  {
    center = {p3.x, p1.y};
    dx = std::abs(p1.x - p2.x) * 2;
    dy = std::abs(center.y - p3.y) * 2;
  }
  else
  {
    throw std::invalid_argument("Diagonals must be parallel to the coordinate axes");
  }
  point_t vertex1 = {center.x + dx / 2, center.y};
  point_t vertex2 = {center.x, center.y - dy / 2};
  point_t vertex3 = {center.x - dx / 2, center.y};
  parallelogram_ = Parallelogram(vertex1, vertex2, vertex3);
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

void smirnov::Diamond::unsafeScale(double k) noexcept
{
  parallelogram_.scale(k);
}
