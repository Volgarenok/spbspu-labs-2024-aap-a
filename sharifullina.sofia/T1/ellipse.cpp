#include "ellipse.hpp"
#include <stdexcept>

const double PI = 3.1415926535;

sharifullina::Ellipse::Ellipse(point_t center, double radiusX, double radiusY):
  center_(center), radiusX_(radiusX), radiusY_(radiusY)
{}

double sharifullina::Ellipse::getArea() const
{
  return PI * radiusX_ * radiusY_;
}

sharifullina::rectangle_t sharifullina::Ellipse::getFrameRect() const
{
  return {2 * radiusX_, 2 * radiusY_, center_};
}

void sharifullina::Ellipse::move(const point_t p)
{
  center_ = p;
}

void sharifullina::Ellipse::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void sharifullina::Ellipse::scale(double k)
{
  radiusX_ *= k;
  radiusY_ *= k;
}