#include "ellipse.hpp"
#include <cmath>
#include <stdexcept>

sveshnikov::Ellipse::Ellipse(point_t center, double vert_radius, double horiz_radius):
  center_(center),
  vert_radius_(vert_radius),
  horiz_radius_(horiz_radius)
{
  if (vert_radius_ <= 0 || horiz_radius_ <= 0)
  {
    throw std::logic_error("ERROR: incorrect radius values of ellipse");
  }
}

double sveshnikov::Ellipse::getArea() const
{
  const double pi = 4.0 * atan(1.0);
  return pi * (vert_radius_ * horiz_radius_);
}

sveshnikov::rectangle_t sveshnikov::Ellipse::getFrameRect() const
{
  return {2 * horiz_radius_, 2 * vert_radius_, center_};
}

void sveshnikov::Ellipse::move(const point_t p)
{
  center_ = p;
}

void sveshnikov::Ellipse::move(double dx, double dy)
{
  center_ = movePoint(center_, dx, dy);
}

void sveshnikov::Ellipse::unsafeScale(double k)
{
  vert_radius_ *= k;
  horiz_radius_ *= k;
}

sveshnikov::Shape *sveshnikov::Ellipse::clone() const
{
  return new Ellipse(center_, vert_radius_, horiz_radius_);
}
