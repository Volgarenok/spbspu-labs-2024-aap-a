#include "triangle.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"

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
  return {max_x - min_x, max_y - min_y, {(min_x + max_x) / 2.0, (min_y + max_y) / 2.0}};
}

void komarova::Triangle::move(point_t point)
{
  point_t center = {(a_.x + b_.x + c_.x) / 3.0, (a_.y + b_.y + c_.y) / 3.0};
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}

void komarova::Triangle::move(double dx, double dy)
{
  a_ = {a_.x + dx, a_.y + dy};
  b_ = {b_.x + dx, b_.y + dy};
  c_ = {c_.x + dx, c_.y + dy};
}

void komarova::Triangle::scale(double coef)
{
  if (coef <= 0.0)
  {
    throw std::logic_error("incorrect coefficient");
  }
  point_t center = {(a_.x + b_.x + c_.x) / 3.0, (a_.y + b_.y + c_.y) / 3.0};
  a_.x = center.x + (a_.x - center.x) * coef;
  a_.y = center.y + (a_.y - center.y) * coef;
  b_.x = center.x + (b_.x - center.x) * coef;
  b_.y = center.y + (b_.y - center.y) * coef;
  c_.x = center.x + (c_.x - center.x) * coef;
  c_.y = center.y + (c_.y - center.y) * coef;
}
