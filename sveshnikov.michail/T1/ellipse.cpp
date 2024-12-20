#include "ellipse.hpp"
#include <cmath>

sveshnikov::Ellipse::Ellipse(point_t center, double vert_radius, double horiz_radius):
  center_(center),
  vert_radius_(vert_radius),
  horiz_radius_(horiz_radius)
{}

double sveshnikov::Ellipse::getArea() const
{
  return M_PI * (vert_radius_ * horiz_radius_);
}

sveshnikov::rectangle_t sveshnikov::Ellipse::getFrameRect() const
{
  return {2 * horiz_radius_, 2 * vert_radius_, center_};
}

void sveshnikov::Ellipse::move(point_t p)
{
  center_ = p;
}

void sveshnikov::Ellipse::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void sveshnikov::Ellipse::scale(double k)
{
  vert_radius_ *= k;
  horiz_radius_ *= k;
}
