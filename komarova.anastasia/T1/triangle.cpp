#include "triangle.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include "base-types.hpp"

komarova::Triangle::Triangle(point_t a, point_t b, point_t c):
  a_(a),
  b_(b),
  c_(c)
{
  if ((std::abs(a_.x * (b_.y - c_.y) + b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y)) * 0.5) == 0)
  {
    throw std::logic_error("incorrect triangle");
  }
}
double komarova::Triangle::getArea() const
{
  return (std::abs(a_.x * (b_.y - c_.y) + b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y)) * 0.5);
}
komarova::rectangle_t komarova::Triangle::getFrameRect() const
{
  double min_x = std::min(std::min(a_.x, b_.x), c_.x);
  double max_x = std::max(std::max(a_.x, b_.x), c_.x);
  double min_y = std::min(std::min(a_.y, b_.y), c_.y);
  double max_y = std::max(std::max(a_.y, b_.y), c_.y);
  return { max_x - min_x, max_y - min_y, { (min_x + max_x) / 2.0, (min_y + max_y) / 2.0 } };
}
void komarova::Triangle::move(point_t point)
{
  point_t center = getFrameRect().pos;
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}
void komarova::Triangle::move(double dx, double dy)
{
  a_ = { a_.x + dx, a_.y + dy };
  b_ = { b_.x + dx, b_.y + dy };
  c_ = { c_.x + dx, c_.y + dy };
}
void komarova::Triangle::scaleUnsafe(double coef)
{
  point_t center = getFrameRect().pos;
  a_ = scalePoint(a_, center, coef);
  b_ = scalePoint(b_, center, coef);
  c_ = scalePoint(c_, center, coef);
}
