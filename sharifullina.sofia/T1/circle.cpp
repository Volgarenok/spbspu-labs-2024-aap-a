#include "circle.hpp"
#include <stdexcept>

constexpr double PI = 3.1415926535;

sharifullina::Circle::Circle(point_t center, double radius):
  Ellipse(center, radius, radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Radius must be positive.");
  }
}

double sharifullina::Circle::getArea() const
{
  return Ellipse::getArea();
}

sharifullina::rectangle_t sharifullina::Circle::getFrameRect() const
{
  return Ellipse::getFrameRect();
}

void sharifullina::Circle::move(point_t p)
{
  Ellipse::move(p);
}

void sharifullina::Circle::move(double dx, double dy)
{
  Ellipse::move(dx, dy);
}

void sharifullina::Circle::scale(double k)
{
  Ellipse::scale(k);
}
