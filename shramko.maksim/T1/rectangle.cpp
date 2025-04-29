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
    center_.x = leftBottom_.x + (rightTop_.x - leftBottom_.x)/2;
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
  double height = rightTop_.y - leftBottom_.y;
  double width = rightTop_.x - leftBottom_.x;
  double x_ = leftBottom_.x + (width / 2.0);
  double y_ = leftBottom_.y + (height / 2.0);

  return {width, height, {x_, y_}};
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

void shramko::Rectangle::doScale(double k)
{
  const point_t center = getFrameRect().pos;

  leftBottom_.x = center.x + (leftBottom_.x - center.x) * k;
  leftBottom_.y = center.y + (leftBottom_.y - center.y) * k;

  rightTop_.x = center.x + (rightTop_.x - center.x) * k;
  rightTop_.y = center.y + (rightTop_.y - center.y) * k;
}
