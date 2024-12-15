#include "rectangle.hpp"
#include <stdlib.h>
#include <stdexcept>
#include <cmath>


dribas::Rectangle::Rectangle(Point_t leftDown, Point_t rightUp): leftDown_({0.0L, 0.0L}), rightUp_({0.0L, 0.0L})
{
  if (rightUp.x_ < leftDown.x_ || rightUp.y_ < leftDown.y_) {
    throw std::invalid_argument("error with rectangle size\n");
  }
  rightUp_.x_ = rightUp.x_;
  rightUp_.y_ = rightUp.y_;
  leftDown_.x_ = leftDown.x_;
  leftDown_.y_ = leftDown.y_;
}
double dribas::Rectangle::getArea() const
{
  double weight = rightUp_.x_ - leftDown_.x_;
  double hieght = rightUp_.y_ - leftDown_.y_;
  return weight * hieght;
}
dribas::Rectangle_t dribas::Rectangle::getFrameRect() const
{
  Rectangle_t result;
  result.height_ = rightUp_.y_ - leftDown_.y_;
  result.width_ = rightUp_.x_ - leftDown_.x_;
  result.pos_.x_ = leftDown_.x_ + (result.width_ / 2.0L);
  result.pos_.y_ = leftDown_.y_ + (result.height_ / 2.0L);
  return result;
}

void dribas::Rectangle::move(double x, double y)
{
  leftDown_.x_ += x;
  leftDown_.y_ += x;
  rightUp_.x_ += y;
  leftDown_.y_ += y;
}

void dribas::Rectangle::move(Point_t centerP)
{
  Point_t pos = getFrameRect().pos_;
  double moveX = centerP.x_ - pos.x_;
  double moveY = centerP.y_ - pos.y_;
  move(moveX, moveY);
}

void dribas::Rectangle::scale(double ratio)
{
  if (ratio <= 0) {
    throw std::invalid_argument("under zero ratio with scale\n");
  }
  Rectangle_t fremRect = getFrameRect();
  Point_t pos = fremRect.pos_;
  rightUp_.x_ = pos.x_ + fremRect.width_ / 2.0L * ratio;
  rightUp_.y_ = pos.y_ + fremRect.height_ / 2.0L * ratio;
  leftDown_.x_ = pos.x_ - fremRect.width_ / 2.0L * ratio;
  leftDown_.y_ = pos.y_ - fremRect.height_ / 2.0L * ratio;
}
