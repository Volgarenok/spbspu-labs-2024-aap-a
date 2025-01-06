#include "rectangle.hpp"
#include <stdexcept>

brevnov::Rectangle::Rectangle(point_t left, point_t right):
  left_(left),
  right_(right)
{}

double brevnov::Rectangle::getArea() const noexcept
{
  return (right_.x_ - left_.x_) * (right_.y_ - left_.y_);
}

brevnov::rectangle_t brevnov::Rectangle::getFrameRect() const noexcept
{
  double width = right_.x_ - left_.x_;
  double height = right_.y_ - left_.y_;
  point_t pos = {left_.x_ + width / 2.0, left_.y_ + height / 2.0};
  rectangle_t result(width, height, pos);
  return result;
}

void brevnov::Rectangle::move(point_t new_centre) noexcept
{
  point_t old_centre = getFrameRect().pos_;
  double dx_ = new_centre.x_ - old_centre.x_;
  double dy_ = new_centre.y_ - old_centre.y_;
  move(dx, dy);
}

void brevnov::Rectangle::move(double dx, double dy) noexcept
{
  left_.x_ += dx;
  left_.y_ += dy;
  right_.x_ += dx;
  right_.y_ += dy;
}

void brevnov::Rectangle::scale(double n) noexcept
{
  point_t centre = getFrameRect().pos_;
  left_ = {centre.x_ + (left_.x_ - centre.x_) * n, centre.y_ + (left_.y_ - centre.y_) * n};
  right_ = {centre.x_ + (right_.x_ - centre.x_) * n, centre.y_ + (right_.y_ - centre.y_) * n};
}
