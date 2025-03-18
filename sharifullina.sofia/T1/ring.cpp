#include "ring.hpp"
#include <stdexcept>

constexpr double PI = 3.1415926535;
sharifullina::Ring::Ring(point_t center, double inRadius, double outRadius):
  inner_(center, inRadius),
  outer_(center, outRadius)
{
  if (inRadius <= 0.0 || outRadius <= 0.0)
  {
    throw std::invalid_argument("Radius must be positive.");
  }
  if (inRadius >= outRadius)
  {
    throw std::invalid_argument("outRadius must be larger than inRadius.");
  }
}

double sharifullina::Ring::getArea() const
{
  return outer_.getArea() - inner_.getArea();
}

sharifullina::rectangle_t sharifullina::Ring::getFrameRect() const
{
  return outer_.getFrameRect();
}

void sharifullina::Ring::move(point_t p)
{
  inner_.move(p);
  outer_.move(p);
}

void sharifullina::Ring::move(double dx, double dy)
{
  inner_.move(dx, dy);
  outer_.move(dx, dy);
}

void sharifullina::Ring::scaleWithoutCheck(double k)
{
  inner_.scaleWithoutCheck(k);
  outer_.scaleWithoutCheck(k);
}
