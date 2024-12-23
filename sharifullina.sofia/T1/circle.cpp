#include "circle.hpp"
#include <stdexcept>

const double PI = 3.1415926535;

sharifullina::Circle::Circle(point_t center, double radius) :
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Radius must be positive.");
  }
}

double sharifullina::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

sharifullina::rectangle_t sharifullina::Circle::getFrameRect() const
{
  double diameter = 2.0 * radius_;
  return {diameter, diameter, center_};
}

void sharifullina::Circle::move(point_t p)
{
  center_ = p;
}

void sharifullina::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void sharifullina::Circle::scale(double k)
{
  radius_ *= k;
}
