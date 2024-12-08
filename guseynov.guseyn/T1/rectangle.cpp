#include "rectangle.hpp"

guseynov::Rectangle::Rectangle(point_t leftLowP, point_t rightHighP)
{
  if (leftLowP.x >= rightHighP.x || leftLowP.y >= rightHighP.y)
  {
    throw std::logic_error("Invalid argumets for Rectangle");
  }
  leftLowP_.x = leftLowP.x;
  leftLowP_.y = leftLowP.y;
  rightHighP_.x = rightHighP.x;
  rightHighP_.y = rightHighP.y;
}

double guseynov::Rectangle::getArea() const
{
  return (rightHighP_.x - leftLowP_.x) * (rightHighP_.y - leftLowP_.y);
}

guseynov::rectangle_t guseynov::Rectangle::getFrameRect() const
{
  double width = rightHighP_.x - leftLowP_.x;
  double height = rightHighP_.y - leftLowP_.y;
  return {width, height, {leftLowP_.x + (width / 2), leftLowP.y + (height / 2)}};
}

void guseynov::Rectangle::move(point_t pos)
{
  point_t center = getFrameRect().pos;
  double moveX = pos.x - center.x;
  double moveY = pos.y - center.y;
  leftLowP_.x += moveX;
  leftLowP_.y += moveY;
  rightHighP_.x += moveX;
  rightHighP_.y += moveY;
}

void guseynov::Rectangle::move(double x, double y)
{
  leftLowP_.x += x;
  leftLowP_.y += y;
  rightHighP_.x += x;
  rightHighP_.y += y;
}

void guseynov::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Invalid argument for k")
  }
  point_t center = getFrameRect().pos;
  leftLowP_.x = center.x - (center.x - leftLowP_.x) * k;
  leftLowP_.y = center.y - (center.y - leftLowP_.y) * k;
  rightHighP_.x = center.x + (center.x - rightHighP_.x) * k;
  rightHighP_.y = center.y + (center.y - rightHighP_.y) * k;
}
