#include "rectangle.hpp"
#include <stdlib.h>
#include <stdexcept>
#include <cmath>


dribas::Rectangle::Rectangle(point_t leftDown, point_t rightUp): leftDown_({0.0L, 0.0L}), rightUp_({0.0L, 0.0L})
{
  if (leftDown.x < rightUp.x && leftDown.y < rightUp.y) {
    rightUp_.x = rightUp.x;
    rightUp_.y = rightUp.y;
    leftDown_.x = leftDown.x;
    leftDown_.y = leftDown.y;
  } else if (leftDown.x > rightUp.x && leftDown.y > rightUp.y) {
    rightUp_.x = leftDown.x;
    rightUp_.y = leftDown.y;
    leftDown_.x = rightUp.x;
    leftDown_.y = rightUp.y;
  } else {
    throw std::invalid_argument("error with rectangle size\n");
  }
}
double dribas::Rectangle::getArea() const
{
  double weight = rightUp_.x - leftDown_.x;
  double hieght = rightUp_.y - leftDown_.y;
  return weight * hieght;
}
dribas::rectangle_t dribas::Rectangle::getFrameRect() const
{
  rectangle_t result;
  result.height = rightUp_.y - leftDown_.y;
  result.width = rightUp_.x - leftDown_.x;
  result.pos.x = leftDown_.x + (result.width / 2.0L);
  result.pos.y = leftDown_.y + (result.height / 2.0L);
  return result;
}

void dribas::Rectangle::move(double x, double y)
{
  leftDown_.x += x;
  leftDown_.y += x;
  rightUp_.x += y;
  leftDown_.y += y;
}

void dribas::Rectangle::move(point_t centerP)
{
  point_t pos = getFrameRect().pos;
  double moveX = centerP.x - pos.x;
  double moveY = centerP.y - pos.y;
  move(moveX, moveY);
}

void dribas::Rectangle::scale(double ratio)
{
  if (ratio <= 0) {
    throw std::invalid_argument("under zero ratio with scale\n");
  }
  rectangle_t fremRect = getFrameRect();
  point_t pos = fremRect.pos;
  rightUp_.x = pos.x + fremRect.width / 2.0L * ratio;
  rightUp_.y = pos.y + fremRect.height / 2.0L * ratio;
  leftDown_.x = pos.x - fremRect.width / 2.0L * ratio;
  leftDown_.y = pos.y - fremRect.height / 2.0L * ratio;
}
