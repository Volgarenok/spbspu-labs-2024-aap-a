#include "rectangle.hpp"
#include <stdexcept>
alymova::Rectangle::Rectangle(const point_t& p1, const point_t& p2):
  low_left_(p1),
  upp_right_(p2)
{
  if (p2 < p1)
  {
    throw std::logic_error("Incorrect description rectangle");
  }
}
alymova::Rectangle::Rectangle(const Rectangle& other):
  low_left_(other.low_left_),
  upp_right_(other.upp_right_)
{}
double alymova::Rectangle::getArea() const noexcept
{
  double width = getFrameRect().width;
  double height = getFrameRect().height;
  return width * height;
}
alymova::rectangle_t alymova::Rectangle::getFrameRect() const noexcept
{
  double width = upp_right_.x - low_left_.x;
  double height = upp_right_.y - low_left_.y;
  point_t pos = {(low_left_.x + width / 2.0), (upp_right_.y - height / 2.0)};
  return rectangle_t{width, height, pos};
}
void alymova::Rectangle::move(double shift_x, double shift_y) noexcept
{
  point_t shift_point{shift_x, shift_y};
  low_left_ += shift_point;
  upp_right_ += shift_point;
}
void alymova::Rectangle::move(const point_t& point) noexcept
{
  point_t pos = {getFrameRect().pos};
  double shift_x = point.x - pos.x;
  double shift_y = point.y - pos.y;
  move(shift_x, shift_y);
}
void alymova::Rectangle::unsafeScale(double ratio) noexcept
{
  double width = getFrameRect().width;
  double height = getFrameRect().height;
  low_left_ += (point_t{0.5 * (width - ratio * width), 0.5 * (height - ratio * height)});
  upp_right_ += (point_t{0.5 * (ratio * width - width), 0.5 * (ratio * height - height)});
}
alymova::Shape* alymova::Rectangle::clone() const
{
  return new Rectangle(*this);
}
