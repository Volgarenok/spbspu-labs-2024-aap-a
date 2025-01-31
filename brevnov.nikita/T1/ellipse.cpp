#include "ellipse.hpp"
#include <cmath>
#include <stdexcept>

brevnov::Ellipse::Ellipse(point_t center, double r1, double r2):
  center_(center),
  r1_(0.0),
  r2_(0.0)
{
  if (r1 == 0.0 || r2 == 0.0)
  {
    throw std::invalid_argument("Not correct arguments");
  }
  r1_ = r1;
  r2_ = r2;
}

double brevnov::Ellipse::getR1() const noexcept
{
  return r1_;
}

double brevnov::Ellipse::getR2() const noexcept
{
  return r2_;
}

void brevnov::Ellipse::updateEllipse(point_t center, double r1, double r2)
{
  center_ = center;
  r1_ = r1;
  r2_ = r2;
}

double brevnov::Ellipse::getArea() const noexcept
{
  const double pi = std::acos(-1.0);
  return pi * r1_ * r2_;
}

brevnov::rectangle_t brevnov::Ellipse::getFrameRect() const noexcept
{
  point_t pos = center_;
  double width = r2_ * 2.0;
  double height = r1_ * 2.0;
  rectangle_t result(width, height, pos);
  return result;
}

void brevnov::Ellipse::move(point_t new_centre) noexcept
{
  center_ = new_centre;
}

void brevnov::Ellipse::move(double dx, double dy) noexcept
{
  center_.x += dx;
  center_.y += dy;
}

void brevnov::Ellipse::scale(double n) noexcept
{
  r1_ *= n;
  r2_ *= n;
}
