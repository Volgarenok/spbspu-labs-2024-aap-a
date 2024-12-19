#include "ring.hpp"
#include <cmath>

sveshnikov::Ring::Ring(point_t center, double short_radius, double long_radius): 
  center_(center),
  short_radius_(short_radius),
  long_radius_(long_radius)
{}

double sveshnikov::Ring::getArea() const
{
  return M_PI * (long_radius_ * long_radius_ - short_radius_ * short_radius_);
}

sveshnikov::rectangle_t sveshnikov::Ring::getFrameRect() const
{
  rectangle_t frame = {0, 0, {0, 0}};
  frame.height = 2 * long_radius_;
  frame.width = 2 * long_radius_;
  frame.pos.x = center_.x;
  frame.pos.y = center_.y;
  return frame;
}

void sveshnikov::Ring::move(point_t p)
{
  center_.x = p.x;
  center_.y = p.y;
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
