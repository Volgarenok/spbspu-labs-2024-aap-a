#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"

komarova::Rectangle::Rectangle(point_t low_left, point_t up_right):
  low_left_(low_left),
  up_right_(up_right)
{
  if (low_left_.x >= up_right_.x || low_left_.y >= up_right_.y)
  {
    throw std::logic_error("incorrect coordinates");
  }
}
double komarova::Rectangle::getArea() const
{
  double width_ = up_right_.x - low_left_.x;
  double height_ = up_right_.y - low_left_.y;
  return (width_ * height_);
}
komarova::rectangle_t komarova::Rectangle::getFrameRect() const
{
  double width_ = up_right_.x - low_left_.x;
  double height_ = up_right_.y - low_left_.y;
  point_t pos_ = {(low_left_.x + width_ / 2.0), (low_left_.y + height_ / 2.0)};
  return {width_, height_, pos_};
}
void komarova::Rectangle::move(point_t point)
{
  double dx = point.x - getFrameRect().pos.x;
  double dy = point.y - getFrameRect().pos.y;
  low_left_ = {low_left_.x + dx, low_left_.y + dy};
  up_right_ = {up_right_.x + dx, up_right_.y + dy};
}
void komarova::Rectangle::move(double dx, double dy)
{
  low_left_ = {low_left_.x + dx, low_left_.y + dy};
  up_right_ = {up_right_.x + dx, up_right_.y + dy};
}
void komarova::Rectangle::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::logic_error("incorrect coef");
  }
  point_t center = getFrameRect().pos;
  low_left_.x = center.x + (low_left_.x - center.x) * coef;
  low_left_.y = center.y + (low_left_.y - center.y) * coef;
  up_right_.x = center.x + (up_right_.x - center.x) * coef;
  up_right_.y = center.y + (up_right_.y - center.y) * coef;
}
