#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>


shramko::Rectangle::Rectangle(point_t leftBottom, point_t rightTop):
  leftBottom_(leftBottom),
  rightTop_(rightTop)
{
  if (leftBottom.x < rightTop.x && leftBottom.y < rightTop.y)
  {
    leftBottom_.x = leftBottom.x;
    leftBottom_.y = leftBottom.y;
    rightTop_.x = rightTop.x;
    rightTop_.y = rightTop.y;
    center_.x = leftBottom_.x+(rightTop_.x - leftBottom_.x)/2;
    center_.y = leftBottom.y +(rightTop_.y - leftBottom_.y)/2;
  }
  else
  {
    throw std::invalid_argument("Rect size err\n");
  }
}

double shramko::Rectangle::getArea() const
{
  double weight = rightTop_.x - leftBottom_.x;
  double height = rightTop_.y - leftBottom_.y;

  return weight * height;
}

shramko::rectangle_t shramko::Rectangle::getFrameRect() const
{
  rectangle_t rectFrame;
  rectFrame.height = rightTop_.y - leftBottom_.y;
  rectFrame.width = rightTop_.x - leftBottom_.x;
  rectFrame.pos = center_;

  return rectFrame;
}

void shramko::Rectangle::move(double x, double y)
{
  leftBottom_.x += x;
  leftBottom_.y += y;
  rightTop_.x += x;
  rightTop_.y += y;
  center_.x += x;
  center_.y += y;
}

void shramko::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Rect scale err\n");
  }

  leftBottom_.x *= k;
  rightTop_.x *= k;
  rightTop_.y *= k;
  leftBottom_.y *= k;
}
