#include "ring.hpp"
#include <cmath>

sveshnikov::Ring::Ring(point_t center, double long_radius, double short_radius):
  center_(center),
  long_radius_(long_radius),
  short_radius_(short_radius)
{}

double sveshnikov::Ring::getArea() const
{
  return M_PI * (long_radius_ * long_radius_ - short_radius_ * short_radius_);
}

sveshnikov::rectangle_t sveshnikov::Ring::getFrameRect() const
{
  return {2 * long_radius_, 2 * long_radius_, center_};
}

void sveshnikov::Ring::move(const point_t p)
{
  center_ = p;
}

void sveshnikov::Ring::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void sveshnikov::Ring::scale(double k)
{
  long_radius_ *= k;
  short_radius_ *= k;
}
