#include "ring.hpp"
#include <stdexcept>

krylov::Ring::Ring(const point_t& center, double outerRadius, double innerRadius):
  center_(center),
  outerRadius_(outerRadius),
  innerRadius_(innerRadius)
{
  if (outerRadius <= 0 || innerRadius <= 0 || innerRadius >= outerRadius)
  {
    throw std::invalid_argument("Invalid ring coordinates");
  }
}

double krylov::Ring::getArea() const
{
  constexpr double piNumber = 3.14;
  return piNumber * (outerRadius_ * outerRadius_ - innerRadius_ * innerRadius_);
}

krylov::rectangle_t krylov::Ring::getFrameRect() const
{
  return {outerRadius_ * 2, outerRadius_ * 2, center_};
}

void krylov::Ring::move(const point_t& point)
{
  center_ = point;
}

void krylov::Ring::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void krylov::Ring::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }
  outerRadius_ *= factor;
  innerRadius_ *= factor;
}
