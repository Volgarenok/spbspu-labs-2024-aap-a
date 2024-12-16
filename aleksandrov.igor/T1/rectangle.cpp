#include "rectangle.hpp"
#include "base-types.hpp"
#include <cmath>

aleksandrov::Rectangle::Rectangle(const point_t& a, const point_t& b):
  a_(a), b_(b)
{}

double aleksandrov::Rectangle::getArea() const
{
  return std::fabs((b_.x - a_.x) * (b_.y - a_.y));
}

aleksandrov::rectangle_t aleksandrov::Rectangle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width = std::fabs(b_.x - a_.x);
  frameRect.height = std::fabs(b_.y - a_.y);
  point_t centerPoint;
  centerPoint.x = a_.x + ((b_.x - a_.x) / 2);
  centerPoint.y = a_.y + ((b_.y - a_.y) / 2);
  frameRect.pos = centerPoint;
  return frameRect;
}

void aleksandrov::Rectangle::move(const point_t& centerPoint)
{
  rectangle_t frameRect = getFrameRect();
  frameRect.pos = centerPoint;
  a_.x = frameRect.pos.x - frameRect.width / 2;
  a_.y = frameRect.pos.y - frameRect.height / 2;
  b_.x = frameRect.pos.x + frameRect.width / 2;
  b_.y = frameRect.pos.y + frameRect.height / 2;
}

void aleksandrov::Rectangle::move(const double dx, const double dy)
{
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
}

void aleksandrov::Rectangle::scale(const size_t k)
{
  point_t center = getFrameRect().pos;
  a_.x = center.x + (a_.x - center.x) * k;
  a_.y = center.y + (a_.y - center.y) * k;
  b_.x = center.x + (b_.x - center.x) * k;
  b_.y = center.y + (b_.y - center.y) * k;
}
