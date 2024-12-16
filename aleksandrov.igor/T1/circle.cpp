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
  frameRect.width = 2 * r_;
  frameRect.height = 2 * r_;
  frameRect.pos = center_;
  return frameRect;
}

void aleksandrov::Circle::move(const point_t& centerPoint)
{
  center_.x = centerPoint.x;
  center_.y = centerPoint.y;
}

void aleksandrov::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void aleksandrov::Circle::scale(double k)
{
  point_t centerPoint = getFrameRect().pos;
  center_.x = center_.x + (center_.x - centerPoint.x) * k;
  center_.y = center_.y + (center_.y - centerPoint.y) * k;
  r_ *= k;
}

