#include "ellipse.hpp"
#include <cmath>

brevnov::Ellipse::Ellipse(point_t center, double r1, double r2):
  center_(center),
  r1_(r1),
  r2_(r2)
{
}

double brevnov::Ellipse::getArea() const
{
  const double pi = std::acos(-1.0);
  return pi * r1_ * r2_;
}

brevnov::rectangle_t brevnov::Ellipse::getFrameRect() const
{
  point_t pos = center_;
  double width = r2_ * 2.0;
  double height = r1_ * 2.0;
  rectangle_t result(width, height, pos);
  return result;
}

void brevnov::Ellipse::move(point_t new_centre)
{
  center_ = new_centre;
}

void brevnov::Ellipse::move(double dx, double dy)
{
  center_.x_ += dx;
  center_.y_ += dy;
}

void brevnov::Ellipse::scale(double n)
{
  r1_ *= n;
  r2_ *= n;
}
