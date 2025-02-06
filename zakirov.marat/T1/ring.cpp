#include "ring.hpp"
#include <cmath>
#include <stdexcept>
#include "unified_shapes.hpp"

zakirov::Ring::Ring(const point_t & center, double ex_radius, double in_radius):
  center_(center),
  ex_radius_(ex_radius),
  in_radius_(in_radius)
{
  if (in_radius >= ex_radius || ex_radius <= 0 || in_radius <= 0)
  {
    throw std::invalid_argument("Incorrect data");
  }
}

double zakirov::Ring::getArea() const
{
  constexpr double pi = 3.14;
  double ex_area = pi * std::pow(ex_radius_, 2);
  double in_area = pi * std::pow(in_radius_, 2);

  return ex_area - in_area;
}

zakirov::rectangle_t zakirov::Ring::getFrameRect() const
{
  return {ex_radius_ * 2, ex_radius_ * 2, center_};
}

void zakirov::Ring::move(const point_t & target)
{
  center_ = target;
}

void zakirov::Ring::move(double bias_x, double bias_y)
{
  move_point(center_, bias_x, bias_y);
}

void zakirov::Ring::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect coefficient");
  }

  in_radius_ *= k;
  ex_radius_ *= k;
}

zakirov::Shape * zakirov::Ring::clone() const
{
  return make_ring(center_.x, center_.y, ex_radius_, in_radius_);
}
