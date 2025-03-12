#include "rectangle.hpp"
#include <stdexcept>

ivanova::Rectangle::Rectangle(point_t leftBottom, point_t rightTop):
 leftBottom_(leftBottom),
 rightTop_(rightTop)
{
  if (leftBottom.x >= rightTop.x || leftBottom.y >= rightTop.y)
  {
    throw std::invalid_argument("Invalid rectangle parameters: bottomLeft must be less than topRight.");
  }
}

double ivanova::Rectangle::getArea() const
{
  double width = rightTop_.x - leftBottom_.x;
  double height = rightTop_.y - leftBottom_.y;
  return width * height;
}

ivanova::rectangle_t ivanova::Rectangle::getFrameRect() const
{
  double width = rightTop_.x - leftBottom_.x;
  double height = rightTop_.y - leftBottom_.y;
  ivanova::point_t pos = { leftBottom_.x + width / 2.0, leftBottom_.y + height / 2.0 };
  return {height, width, pos};
}

void ivanova::Rectangle::move(point_t point)
{
  double moveX = point.x - getFrameRect().pos.x;
  double moveY = point.y - getFrameRect().pos.y;
  leftBottom_ = {leftBottom_.x + moveX, leftBottom_.y + moveY};
  rightTop_ = {rightTop_.x + moveX, rightTop_.y + moveY};
}

void ivanova::Rectangle::move(double x, double y)
{
  leftBottom_ = {leftBottom_.x + x, leftBottom_.y + y};
  rightTop_ = {rightTop_.x + x, rightTop_.y + y};
}

void ivanova::Rectangle::scale(double ratio)
{
  point_t center = getFrameRect().pos;
  leftBottom_.x = center.x + (leftBottom_.x - center.x) * ratio;
  leftBottom_.y = center.y + (leftBottom_.y - center.y) * ratio;
  rightTop_.x = center.x + (rightTop_.x - center.x) * ratio;
  rightTop_.y = center.y + (rightTop_.y - center.y) * ratio;
}
