#include "circle.hpp"
#include "base-types.hpp"

aleksandrov::Circle::Circle(const point_t& center, const double r):
  center_(center), r_(r)
{}

double aleksandrov::Circle::getArea() const
{
  return 3.14159265 * r_ * r_;
}

aleksandrov::rectangle_t aleksandrov::Circle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width_ = 2 * r_;
  frameRect.height_ = 2 * r_;
  frameRect.pos_ = center_;
  return frameRect;
}

void aleksandrov::Circle::move(const point_t& centerPoint)
{
  center_.x_ = centerPoint.x_;
  center_.y_ = centerPoint.y_;
}

void aleksandrov::Circle::move(const double dx, const double dy)
{
  center_.x_ += dx;
  center_.y_ += dy;
}

void aleksandrov::Circle::scale(const size_t k)
{
  point_t center = getFrameRect().pos_;
  center_.x_ = center.x_ + (center_.x_ - center.x_) * k;
  center_.y_ = center.y_ + (center_.y_ - center.y_) * k;
  r_ *= k;
}

