#include "triangle.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>

dribas::Triangle::Triangle(point_t a, point_t b, point_t c)
{
  if (false){ //Добавлю потом
    throw;
  }
  a_ = a;
  b_ = b;
  c_ = c;
}
double dribas::Triangle::getArea() const
{
    return std::abs(((b_.x_ - a_.x_) * (c_.y_ - a_.y_) - (c_.x_ - a_.x_) * (b_.y_ - a_.y_))) / 2.0;
}
dribas::rectangle_t dribas::Triangle::getFrameRect() const
{
  double maxX = std::max(a_.x_, std::max(b_.x_, c_.x_));
  double maxY = std::max(a_.y_, std::max(b_.y_, c_.y_));
  double minX = std::min(a_.x_, std::min(b_.x_, c_.x_));
  double minY = std::min(a_.y_, std::min(b_.y_, c_.y_));
  dribas::rectangle_t result;
  result.height = maxY - minY;
  result.width = maxX - minY;
  result.pos.x_ = minX + (result.width / 2);
  result.pos.y_ = maxX + (result.height / 2);
  return result;
}
void dribas::Triangle::move(point_t centerP)
{
  dribas::point_t pos;
  pos.x_ = std::abs(a_.x_ + b_.x_ + c_.x_) / 3.0;
  pos.y_ = std::abs(a_.y_ + b_.y_ + c_.y_) / 3.0;
  double moveX = centerP.x_ - pos.x_;
  double moveY = centerP.y_ - pos.y_;
  a_.x_ += moveX;
  a_.y_ += moveY;
  b_.x_ += moveX;
  b_.y_ += moveY;
  c_.x_ += moveX;
  c_.y_ += moveY;
}
void dribas::Triangle::move(double x, double y)
{
  a_.x_ += x;
  a_.y_ += y;
  b_.x_ += x;
  b_.y_ += y;
  c_.x_ += x;
  c_.y_ += y;
}
void dribas::Triangle::scale(double ratio)
{
  if (ratio<= 0) {
    throw std::invalid_argument("under zero ratio\n");
  }
  point_t pos;
  pos.x_ = std::abs(a_.x_ + b_.x_ + c_.x_) / 3.0;
  pos.y_ = std::abs(a_.y_ + b_.y_ + c_.y_) / 3.0;
  double centerA = std::sqrt(std::pow(a_.x_ - pos.x_, 2) + std::pow(a_.y_ - pos.y_, 2));
  double centerB = std::sqrt(std::pow(b_.x_ - pos.x_, 2) + std::pow(b_.y_ - pos.y_, 2));
  double centerC = std::sqrt(std::pow(c_.x_ - pos.x_, 2) + std::pow(c_.y_ - pos.y_, 2));
  centerA *= ratio;
  centerB *= ratio;
  centerC *= ratio;
  a_.x_ = pos.x_ + centerA * std::cos(std::atan2(a_.y_ - pos.y_, a_.x_ - pos.x_));
  a_.y_ = pos.y_ + centerA * std::sin(std::atan2(a_.y_ - pos.y_, a_.x_ - pos.x_));
  b_.x_ = pos.x_ + centerB * std::cos(std::atan2(b_.y_ - pos.y_, b_.x_ - pos.x_));
  b_.y_ = pos.y_ + centerB * std::sin(std::atan2(b_.y_ - pos.y_, b_.x_ - pos.x_));
  c_.x_ = pos.x_ + centerC * std::cos(std::atan2(c_.y_ - pos.y_, c_.x_ - pos.x_));
  c_.y_ = pos.y_ + centerC * std::sin(std::atan2(c_.y_ - pos.y_, c_.x_ - pos.x_));
}
