#include "rectangle.hpp"
#include <stdexcept>

brevnov::Rectangle::Rectangle(point_t left, point_t right):
  left_(left),
  right_(right)
{}

double brevnov::Rectangle::getArea() const noexcept
{
  return (right_.x - left_.x) * (right_.y - left_.y);
}

brevnov::rectangle_t brevnov::Rectangle::getFrameRect() const noexcept
{
  double width = right_.x - left_.x;
  double height = right_.y - left_.y;
  point_t pos = {left_.x + width / 2.0, left_.y + height / 2.0};
  rectangle_t result(width, height, pos);
  return result;
}

void brevnov::Rectangle::move(point_t new_centre) noexcept
{
  point_t old_centre = getFrameRect().pos;
  double dx = new_centre.x - old_centre.x;
  double dy = new_centre.y - old_centre.y;
  move(dx, dy);
}

void brevnov::move_point(point_t punkt, double dx, double dy)
{
  punkt.x += dx;
  punkt.y += dy;
}

void brevnov::Rectangle::move(double dx, double dy) noexcept
{
  move_point(left_, dx, dy);
  move_point(right_, dx, dy);
}

void brevnov::Rectangle::scale(double n) noexcept
{
  point_t centre = getFrameRect().pos;
  left_ = {centre.x + (left_.x - centre.x) * n, centre.y + (left_.y - centre.y) * n};
  right_ = {centre.x + (right_.x - centre.x) * n, centre.y + (right_.y - centre.y) * n};
}
