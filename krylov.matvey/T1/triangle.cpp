#include "triangle.hpp"
#include <cmath>
#include <stdexcept>

krylov::Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c):
  a_(a), b_(b), c_(c)
{
  double area = getArea();
  if (area <= 0)
  {
    throw std::invalid_argument("Invalid triangle coordinates");
  }
}

double krylov::Triangle::getArea() const
{
  return 0.5 * std::fabs(a_.x * (b_.y - c_.y) + b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y));
}

rectangle_t krylov::Triangle::getFrameRect() const
{
  double minX = std::fmin(a_.x, std::fmin(b_.x, c_.x));
  double maxX = std::fmax(a_.x, std::fmax(b_.x, c_.x));
  double minY = std::fmin(a_.y, std::fmin(b_.y, c_.y));
  double maxY = std::fmax(a_.y, std::fmax(b_.y, c_.y));
  point_t center = getCenter();
  return {maxX - minX, maxY - minY, center};
}

void krylov::Triangle::move(const point_t& point)
{
  point_t center = getCenter();
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  a_.x += dx; a_.y += dy;
  b_.x += dx; b_.y += dy;
  c_.x += dx; c_.y += dy;
}

void Triangle::move(double dx, double dy)
{
  a_.x += dx; a_.y += dy;
  b_.x += dx; b_.y += dy;
  c_.x += dx; c_.y += dy;
}

void krylov::Triangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }
  point_t center = getCenter();
  a_.x = center.x + factor * (a_.x - center.x);
  a_.y = center.y + factor * (a_.y - center.y);
  b_.x = center.x + factor * (b_.x - center.x);
  b_.y = center.y + factor * (b_.y - center.y);
  c_.x = center.x + factor * (c_.x - center.x);
  c_.y = center.y + factor * (c_.y - center.y);
}

point_t krylov::Triangle::getCenter() const
{
  return {(a_.x + b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3};
}
