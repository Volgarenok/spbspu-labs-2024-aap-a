#include "rectangle.hpp"

#include <stdexcept>

guseynov::Rectangle::Rectangle(point_t leftLowP, point_t rightHighP):
  leftLowP_(leftLowP),
  rightHighP_(rightHighP)
{
  if ((rightHighP.x <= leftLowP.x) || (rightHighP.y <= leftLowP.y))
  {
    throw std::invalid_argument("Error in RECTANGLE parameters");
  }
}

double guseynov::Rectangle::getArea() const
{
  return (rightHighP_.x - leftLowP_.x) * (rightHighP_.y - leftLowP_.y);
}

guseynov::rectangle_t guseynov::Rectangle::getFrameRect() const
{
  double width = rightHighP_.x - leftLowP_.x;
  double height = rightHighP_.y - leftLowP_.y;
  return {width, height, {leftLowP_.x + (width / 2), leftLowP_.y + (height / 2)}};
}

void guseynov::Rectangle::move(point_t pos)
{
  point_t center = getFrameRect().pos;
  double moveX = pos.x - center.x;
  double moveY = pos.y - center.y;
  assigment({leftLowP_.x + moveX, leftLowP_.y + moveY},
  {rightHighP_.x + moveX, rightHighP_.y + moveY});
}

void guseynov::Rectangle::move(double x, double y)
{
  assigment({leftLowP_.x + x, leftLowP_.y + y},
  {rightHighP_.x + x, rightHighP_.y + y});
}

void guseynov::Rectangle::scaleWithoutCheck(double k)
{
  point_t center = getFrameRect().pos;
  assigment({center.x + (leftLowP_.x - center.x) * k, center.y + (leftLowP_.y - center.y) * k},
  {center.x + (rightHighP_.x - center.x) * k, center.y + (rightHighP_.y - center.y) * k});
}

void guseynov::Rectangle::assigment(point_t leftLowP, point_t rightHighP)
{
  leftLowP_ = leftLowP;
  rightHighP_ = rightHighP;
}

guseynov::Shape * guseynov::Rectangle::clone() const
{
  return new Rectangle(leftLowP_, rightHighP_);
}
