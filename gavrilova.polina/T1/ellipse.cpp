#include "ellipse.hpp"
 #include "pointManip.hpp"

gavrilova::Ellipse::Ellipse(const point_t& center, double radiusY, double radiusX):
  center_(center),
  radiusY_(radiusY),
  radiusX_(radiusX)
{
  if (radiusX <= 0 || radiusY <= 0) {
    throw std::logic_error("Invalid radiuses for ellipse");
  }
}

double gavrilova::Ellipse::getArea() const
{
  constexpr double pi = 3.14159;
  return pi * radiusX_ * radiusY_;
}

gavrilova::rectangle_t gavrilova::Ellipse::getFrameRect() const
{
  double height = 2 * radiusY_;
  double width = 2 * radiusX_;
  point_t pos(center_);
  return {width, height, pos};
}

void gavrilova::Ellipse::move(const point_t& p)
{
  center_ = p;
}

void gavrilova::Ellipse::move(double difX, double difY)
{
  movePoint(center_, difX, difY);
}

void gavrilova::Ellipse::scaleWithoutCheck(double k) noexcept
{
  radiusX_ *= k;
  radiusY_ *= k;
}

gavrilova::Shape* gavrilova::Ellipse::clone() const
{
  return new Ellipse(*this);
}
