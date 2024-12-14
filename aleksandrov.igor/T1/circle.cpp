#include "circle.hpp"
#include "base-types.hpp"

aleksandrov::Circle::Circle(const point_t& center, const double r):
  center_(center), r_(r)
{}

double aleksandrov::Circle::getArea() const
{
  return 3.14159265 * r_ * r_;
}

rectangle_t aleksandrov::Circle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width_ = 2 * r_;
  frameRect.height_ = 2 * r_;
  point_t centerPoint = center_;
  frameRect.pos_ = centerPoint;
  return frameRect;
}

void aleksandrov::Circle::move(const point_t& centerPoint)
{
  center_ = centerPoint;
}

void aleksandrov::Circle::move(const double dx, const double dy)
{
  center_.x_ += dx;
  center_.y_ += dy;
}

void aleksandrov::Circle::scale(size_t k)
{
  r_ *= k;
}

