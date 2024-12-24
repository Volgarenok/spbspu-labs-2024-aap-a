#include "parallelogram.hpp"

#include <cmath>

guseynov::Parallelogram::Parallelogram(guseynov::point_t leftLowP, guseynov::point_t rightLowP, guseynov::point_t leftHighP)
{
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
  return {width, height, {leftLowP_.x + (width / 2), leftLowP_.y + (height / 2)}};
}

void guseynov::Parallelogram::move(guseynov::point_t pos)
{
  guseynov::point_t center = getFrameRect().pos;
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
  rightLowP_.x += x;
  rightLowP_.y += y;
  leftHighP_.x += x;
  leftHighP_.y += y;
}

void guseynov::Parallelogram::scale(double k)
{
  guseynov::point_t center = getFrameRect().pos;
  leftLowP_.x = center.x - (center.x - leftLowP_.x) * k;
  leftLowP_.y = center.y - (center.y - leftLowP_.y) * k;
  rightLowP_.x = center.x + (center.x - rightLowP_.x) * k;
  rightLowP_.y = center.y - (center.y - rightLowP_.y) * k;
  leftHighP_.x = center.x - fabs(center.x - leftHighP_.x) * k;
  leftHighP_.y = center.y - fabs(center.y - leftHighP_.y) * k;
}
