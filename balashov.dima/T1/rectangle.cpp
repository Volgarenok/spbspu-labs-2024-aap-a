#include "rectangle.hpp"
#include <stdexcept>

balashov::Rectangle::Rectangle(double xLeft, double yUp, double xRight, double yDown)
{
  angleUpRight_.x_ = xRight;
  angleUpRight_.y_ = yUp;
  angleDownLeft_.x_ = xLeft;
  angleDownLeft_.y_ = yDown;
  сentre.x_ = xLeft + (xRight - xLeft) / 2;
  сentre.y_ = yDown + (yUp - yDown) / 2;
}

double balashov::Rectangle::getArea() const
{
  return (angleUpRight_.y_ - angleDownLeft_.y_) * (angleUpRight_.x_ - angleDownLeft_.x_);
}

balashov::rectangle_t balashov::Rectangle::getFrameRect() const
{
  rectangle_t point = {};
  point.width_ = angleUpRight_.x_ - angleDownLeft_.x_;
  point.height_ = angleUpRight_.y_ - angleDownLeft_.y_;
  point.pos_.x_ = сentre.x_;
  point.pos_.y_ = сentre.y_;
  return point;
}

void balashov::Rectangle::move(double x, double y)
{
  angleUpRight_.x_ += x;
  angleDownLeft_.x_ += x;
  angleDownLeft_.y_ += y;
  angleUpRight_.y_ += y;
}

void balashov::Rectangle::move(point_t s)
{
  double distanceBetweenPointsX = s.x_ - сentre.x_;
  double distanceBetweenPointsY = s.y_ - сentre.y_;
  move(distanceBetweenPointsX, distanceBetweenPointsY);
}

void balashov::Rectangle::scale(double k)
{
  angleDownLeft_.x_ = сentre.x_ - (сentre.x_ - angleDownLeft_.x_) * k;
  angleDownLeft_.y_ = сentre.y_ - (сentre.y_ - angleDownLeft_.y_) * k;
  angleUpRight_.x_ = сentre.x_ + (angleUpRight_.x_ - сentre.x_) * k;
  angleUpRight_.y_ = сentre.y_ + (angleUpRight_.y_ - сentre.y_) * k;
}


