#include "rectangle.hpp"
#include "base-types.hpp"
#include <cmath>

Rectangle::Rectangle(const point_t& a, const point_t& b):
  a_(a), b_(b)
{}

double Rectangle::getArea() const
{
  return std::fabs((b_.x_ - a_.x_) * (b_.y_ - a_.y_));
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width_ = std::fabs(b_.x_ - a_.x_);
  frameRect.height_ = std::fabs(b_.y_ - a_.y_);
  point_t centerPoint;
  centerPoint.x_ = a_.x_ + ((b_.x_ - a_.x_) / 2);
  centerPoint.y_ = a_.y_ + ((b_.y_ - a_.y_) / 2);
  frameRect.pos_ = centerPoint;
  return frameRect;
}

