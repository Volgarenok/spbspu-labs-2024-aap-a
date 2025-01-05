#include "ellipse.hpp"
#include <iostream>
#include "base-types.hpp"
gavrilova::Ellipse::Ellipse(const point_t& center, double radiusY, double radiusX) :
  center_(center),
  radiusY_(radiusY),
  radiusX_(radiusX)
{
  if (radiusX <= 0 || radiusY <= 0) {
    throw std::logic_error("Invalid radiuses for ellipse");
  }
}

gavrilova::Ellipse::Ellipse(const Ellipse& other):
  center_(other.center_),
  radiusX_(other.radiusX_),
  radiusY_(other.radiusY_)
{}

double gavrilova::Ellipse::getArea() const {
  return 3.14159 * radiusX_ * radiusY_;
}

gavrilova::rectangle_t gavrilova::Ellipse::getFrameRect() const {
  rectangle_t frameRect;
  frameRect.height = 2 * radiusY_;
  frameRect.width = 2 * radiusX_;
  frameRect.pos.x = center_.x;
  frameRect.pos.y = center_.y;
  return frameRect;
}

void gavrilova::Ellipse::move(point_t p) {
  center_.x = p.x;
  center_.y = p.y;
}

void gavrilova::Ellipse::move(double difX, double difY) {
  center_.x += difX;
  center_.y += difY;
}

void gavrilova::Ellipse::scale(double k) {
  radiusX_ *= k;
  radiusY_ *= k;
}
gavrilova::Shape* gavrilova::Ellipse::clone() const {
  return new Ellipse(*this);
}
