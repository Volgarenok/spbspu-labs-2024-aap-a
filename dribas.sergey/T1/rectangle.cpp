#include "rectangle.hpp"
#include <stdlib.h>
#include <stdexcept>
#include <cmath>
#define PI 3.14159265 

dribas::Rectangle::Rectangle(Point_t leftDown, Point_t rightUp)
{
  if (rightUp.x_ < leftDown.x_ || rightUp_.y_ < leftDown.y_) {
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
  dribas::Rectangle_t result;
  result.height_ = rightUp_.y_ - leftDown_.y_;
  result.width_ = rightUp_.x_ - leftDown_.x_;
  result.pos_.x_ = leftDown_.x_ + (result.width_ / 2);
  result.pos_.y_ = leftDown_.y_ + (result.height_ / 2);
  return result;
}
void dribas::Rectangle::move(Point_t centerP) 
{
  dribas::Point_t pos = getFrameRect().pos_;
  double moveX = centerP.x_ - pos.x_;
  double moveY = centerP.y_ - pos.y_;
  leftDown_.x_ += moveX;
  leftDown_.y_ += moveY;
  rightUp_.x_ += moveX;
  leftDown_.y_ += moveY;
}
void dribas::Rectangle::move(double x, double y)
{
  leftDown_.x_ += x;
  leftDown_.y_ += x;
  rightUp_.x_ += y;
  leftDown_.y_ += y;
}
void dribas::Rectangle::scale(double ratio)
{
  if (ratio <= 0) {
    throw std::invalid_argument("under zero ratio with scale\n");
  }
  dribas::Point_t pos = getFrameRect().pos_;
  double lenght = std::sqrt(std::pow(pos.x_ - rightUp_.x_, 2) - std::pow(pos.y_ - rightUp_.y_, 2));
  lenght *= ratio;
  rightUp_.x_ = pos.x_ + lenght * std::cos(45 * PI / 180.0);
  rightUp_.y_ = pos.y_ + lenght * std::sin(45 * PI / 180.0);
  leftDown_.x_ = pos.x_ + lenght * std::cos(315 * PI / 180.0);
  leftDown_.y_ = pos.y_ + lenght * std::sin(315 * PI / 180.0);
}



