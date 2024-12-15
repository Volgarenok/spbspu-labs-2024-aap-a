#include "ellipse.hpp"
#include "base-types.hpp"

aleksandrov::Ellipse::Ellipse(const point_t& center, const double vr, const double hr):
  center_(center), vr_(vr), hr_(hr)
{}

double aleksandrov::Ellipse::getArea() const
{
  return 3.14159265 * vr_ * hr_;
}

aleksandrov::rectangle_t aleksandrov::Ellipse::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width_ = 2 * hr_;
  frameRect.height_ = 2 * vr_;
  point_t centerPoint = center_;
  frameRect.pos_ = centerPoint;
  return frameRect;
}

void aleksandrov::Ellipse::move(const point_t& centerPoint)
{
  center_ = centerPoint;
}

void aleksandrov::Ellipse::move(const double dx, const double dy)
{
  center_.x_ += dx;
  center_.y_ += dy;
}

void aleksandrov::Ellipse::scale(const size_t k)
{
  vr_ *= k;
  hr_ *= k;
}

