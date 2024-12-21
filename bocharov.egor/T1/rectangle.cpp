#include "rectangle.hpp"
#include <stdlib.h>
#include <stdexcept>
#include <cmath>

bocharov::Rectangle::Rectangle(point_t leftDown, point_t rightUp): leftDown_({0.0L, 0.0L}), rightUp_({0.0L, 0.0L})
{
  if (leftDown.x < rightUp.x && leftDown.y < rightUp.y) 
  {
    rightUp_.x = rightUp.x;
    rightUp_.y = rightUp.y;
    leftDown_.x = leftDown.x;
    leftDown_.y = leftDown.y;
  }
  else
  {
    throw std::invalid_argument("error with rectangle size\n");
  }
}

double bocharov::Rectangle::getArea() const
{
  double weight = rightUp_.x - leftDown_.x;
  double hieght = rightUp_.y - leftDown_.y;
  return weight * hieght;
}

bocharov::rectangle_t bocharov::Rectangle::getFrameRect() const
{
  rectangle_t result;
  result.height = rightUp_.y - leftDown_.y;
  result.width = rightUp_.x - leftDown_.x;
  result.pos.x = leftDown_.x + (result.width / 2.0L);
  result.pos.y = leftDown_.y + (result.height / 2.0L);
  return result;
}

void bocharov::Rectangle::move(double x, double y)
{
  leftDown_.x += x;
  leftDown_.y += y;
  rightUp_.x += x;
  rightUp_.y += y;
}

void bocharov::Rectangle::move(point_t centerP)
{
  point_t pos = getFrameRect().pos;
  double moveX = centerP.x - pos.x;
  double moveY = centerP.y - pos.y;
  move(moveX, moveY);
}

void bocharov::Rectangle::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("under zero ratio with scale\n");
  }
  rectangle_t fremRect = getFrameRect();
  point_t pos = fremRect.pos;
  rightUp_.x = pos.x + (rightUp_.x - pos.x) * ratio;
  rightUp_.y = pos.y + (rightUp_.y - pos.y) * ratio;
  leftDown_.x = pos.x + (leftDown_.x - pos.x) * ratio;
  leftDown_.y = pos.y + (leftDown_.y - pos.y) * ratio;
}
