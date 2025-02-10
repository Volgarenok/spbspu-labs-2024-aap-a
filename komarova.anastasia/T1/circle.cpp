#include "circle.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"

constexpr double PI = std::acos(-1.0);

komarova::Circle::Circle(point_t point_c, double radius):
  point_c_(point_c),
  radius_(radius)
{
  if (radius <= 0.0)
  {
    throw std::logic_error("incorrect radius");
  }
}

double komarova::Circle::getArea() const
{
  return (PI * radius_ * radius_);
}

komarova::rectangle_t komarova::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, point_c_};
}

void komarova::Circle::move(point_t point)
{
  point_c_ = point;
}

void komarova::Circle::move(double dx, double dy)
{
  point_c_ = {point_c_.x + dx, point_c_.y + dy};
}

void komarova::Circle::scale(double coef)
{
  radius_ *= coef;
}
