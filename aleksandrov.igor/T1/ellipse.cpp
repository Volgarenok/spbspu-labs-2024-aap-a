#include "ellipse.hpp"
#include <stdexcept>
#include "base-types.hpp"

aleksandrov::Ellipse::Ellipse(const point_t& center, double vr, double hr):
  center_(center),
  vr_(vr),
  hr_(hr)
{
  if (vr_ <= 0 || hr_ <= 0)
  {
    throw std::logic_error("Incorrect radiuses");
  }
}

double aleksandrov::Ellipse::getArea() const
{
  return 3.14159265 * vr_ * hr_;
}

aleksandrov::rectangle_t aleksandrov::Ellipse::getFrameRect() const
{
  rectangle_t frameRect{2 * hr_, 2 * vr_, center_};
  return frameRect;
}

void aleksandrov::Ellipse::move(const point_t& centerPoint)
{
  center_ = centerPoint;
}

void aleksandrov::Ellipse::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void aleksandrov::Ellipse::unsafeScale(double k)
{
  vr_ *= k;
  hr_ *= k;
}

