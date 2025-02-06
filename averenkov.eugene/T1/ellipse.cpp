#include "ellipse.hpp"
#include <stdexcept>
#include "base-types.hpp"

averenkov::Ellipse::Ellipse(const point_t& center, double radius_v, double radius_h):
  center_(center),
  radius_v_(radius_v),
  radius_h_(radius_h)
{
  if (radius_v <= 0 || radius_h <= 0)
  {
    throw std::invalid_argument("Error in parameters");
  }
}

void averenkov::Ellipse::scaleNonChecked(double factor)
{
  radius_h_ *= factor;
  radius_v_ *= factor;
}

double averenkov::Ellipse::getArea() const
{
  constexpr double pi = 3.1416;
  return pi * radius_h_ * radius_v_;
}

averenkov::rectangle_t averenkov::Ellipse::getFrameRect() const
{
  double width = radius_h_ * 2;
  double height = radius_v_ * 2;
  return { width, height, center_ };
}

void averenkov::Ellipse::move(const point_t& s)
{
  center_ = s;
}

void averenkov::Ellipse::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
