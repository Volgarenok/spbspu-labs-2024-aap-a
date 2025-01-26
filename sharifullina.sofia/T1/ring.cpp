#include "ring.hpp"
#include <stdexcept>

constexpr double PI = 3.1415926535;
sharifullina::Ring::Ring(point_t center, double inRadius, double outRadius):
  center_(center),
  outRadius_(outRadius),
  inRadius_(inRadius)
{
  if (inRadius_ >= outRadius_)
  {
    throw std::invalid_argument("outRadius must be larger than inRadius.");
  }
  if (outRadius_ <= 0.0 || inRadius_ <= 0.0)
  {
    throw std::invalid_argument("Radius must be positive.");
  }
}

double sharifullina::Ring::getArea() const
{
  return PI * (outRadius_ * outRadius_ - inRadius_ * inRadius_);
}

sharifullina::rectangle_t sharifullina::Ring::getFrameRect() const
{
  double diameter = 2.0 * outRadius_;
  return { diameter, diameter, center_ };
}

void sharifullina::Ring::move(point_t p)
{
  center_ = p;
}

void sharifullina::Ring::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void sharifullina::Ring::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive.");
  }
  outRadius_ *= k;
  inRadius_ *= k;
}
