#include "pyyarallelogram.hpp"

#include <exception>
#include <cmath>

guseynov::Parallelogram::Parallelogram(point_t leftLowP, point_t rightLowP, point_t leftHighP)
{
  if (leftLowP.y != rightLowP.y || leftLowP.y == LeftHighP.y || leftLowP.x == leftHighP.x || leftLowP.x >= rightLowP.x )
  {
    throw std::logic_error("Invalid argumets for Parallelogram");
  }
  leftLowP_.x = leftLowP.x;
  leftLowP_.y = leftLowP.y;
  rightLowP_.x = rightLowP.x;
  rightLowP_.y = rightLowP.y;
  leftHighP_.x = leftHighP.x;
  leftHighP_.y = leftHighP.y;
}

double guseynov::Parallelogram::getArea() const
{
  return (fabs((leftHighP_.y - leftLowP_.y) * (rightLowP_.x - leftLowP_.x)));
}

guseynov::rectangle_t guseynov::Parallelogram::getFrameRect() const
{
  double width = rightLowP_.x - leftLowP_.x;
  double height = fabs(leftHighP_.y - leftLowP_.y);
  return {width, height, {leftLowP_.x + (width / 2), leftLowP.y + (height / 2)}};
}

void guseynov::Parallelogram::move(point_t pos)
{
  point_t center = getFrameRect().pos;
  double moveX = pos.x - center.x;
  double moveY = pos.y - center.y;
  leftLowP_.x += moveX;
  leftLowP_.y += moveY;
  rightLowP_.x += moveX;
  rightLowP_.y += moveY;
  leftHighP_.x += moveX;
  leftHighP_.y += moveY;
}

void guseynov::Parallelogram::move(double x, double y)
{
  leftLowP_.x += x;
  leftLowP_.y += y;
  rightHighP_.x += x;
  rightHighP_.y += y;
  leftHighP_.x += x;
  leftHighP_.y += y;
}

void guseynov::Parallelogram::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Invalid argument for k");
  }
  point_t center = getFrameRect().pos;
  leftLowP_.x = center.x - (center.x - leftLowP_.x) * k;
  leftLowP_.y = center.y - (center.y - leftLowP_.y) * k;
  rightLowP_.x = center.x + (center.x - rightLowP_.x) * k;
  rightLowP_.y = center.y - (center.y - rightLowP_.y) * k;
  leftHighP_.x = center.x - fabs(center.x - leftHighP_.x) * k;
  leftHighP_.y = center.y - fabs(center.y - leftHighP_.y) * k;
}
