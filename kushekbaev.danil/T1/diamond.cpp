#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

kushekbaev::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  parallelogram_(p1, p2, p3)
{
  point_t mid;
  double dx = 0.0, dy = 0.0;
  if ((p1.x == p2.x) && ((p1.y == p3.y) || (p2.y == p3.y)))
  {
    mid = {p1.x, p3.y};
    dx = std::abs(mid.x - p3.x) * 2;
    dy = std::abs(p1.y - p2.y) * 2;
  }
  else if ((p1.x == p3.x) && ((p1.y == p2.y) || (p2.y == p3.y)))
  {
    mid = {p3.x, p2.y};
    dx = std::abs(mid.x - p2.x) * 2;
    dy = std::abs(p3.y - p1.y) * 2;
  }
  else if ((p2.x == p3.x) && ((p1.y == p2.y) || (p1.y == p3.y)))
  {
    mid = {p3.x, p1.y};
    dx = std::abs(p1.x - p2.x) * 2;
    dy = std::abs(mid.y - p3.y) * 2;
  }
  else
  {
    throw std::invalid_argument("Diagonals must be parallel to the coordinate axes");
  }
  point_t point1 = {mid.x + dx / 2, mid.y};
  point_t point2 = {mid.x, mid.y - dy / 2};
  point_t point3 = {mid.x - dx / 2, mid.y};
  parallelogram_ = Parallelogram(point1, point2, point3);
}

double kushekbaev::Diamond::getArea() const
{
  return parallelogram_.getArea();
}

kushekbaev::rectangle_t kushekbaev::Diamond::getFrameRect() const
{
  return parallelogram_.getFrameRect();
}

void kushekbaev::Diamond::move(point_t scalePoint)
{
  return parallelogram_.move(scalePoint);
}

void kushekbaev::Diamond::move(double dx, double dy)
{
  return parallelogram_.move(dx, dy);
}

kushekbaev::Shape* kushekbaev::Diamond::clone() const noexcept
{
  return new kushekbaev::Diamond(*this);
}

void kushekbaev::Diamond::doUnsafeScale(double scaleCoeff)
{
  parallelogram_.doUnsafeScale(scaleCoeff);
}
