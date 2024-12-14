#include "rectangle.hpp"
#include "base-types.hpp"
#include <cmath>

aleksandrov::Rectangle::Rectangle(const point_t& a, const point_t& b):
  a_(a), b_(b)
{}

double aleksandrov::Rectangle::getArea() const
{
  return std::fabs((b_.x_ - a_.x_) * (b_.y_ - a_.y_));
}

rectangle_t aleksandrov::Rectangle::getFrameRect() const
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

void aleksandrov::Rectangle::move(const point_t& centerPoint)
{
  rectangle_t frameRect = getFrameRect();
  frameRect.pos_ = centerPoint;
  a_.x_ = frameRect.pos_.x_ - frameRect.width_ / 2;
  a_.y_ = frameRect.pos_.y_ - frameRect.height_ / 2;
  b_.x_ = frameRect.pos_.x_ + frameRect.width_ / 2;
  b_.y_ = frameRect.pos_.y_ + frameRect.height_ / 2;
}

void aleksandrov::Rectangle::move(const double dx, const double dy)
{
  a_.x_ += dx;
  a_.y_ += dy;
  b_.x_ += dx;
  b_.y_ += dy;
}

void aleksandrov::Rectangle::scale(const size_t k)
{
  point_t center = getFrameRect().pos_;
  a_.x_ = center.x_ + (a_.x_ - center.x_) * k;
  a_.y_ = center.y_ + (a_.y_ - center.y_) * k;
  b_.x_ = center.x_ + (b_.x_ - center.x_) * k;
  b_.y_ = center.y_ + (b_.y_ - center.y_) * k;
}
