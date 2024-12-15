#include "concave.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

namespace dribas
{
  bool isTriangle(point_t a, point_t b, point_t c);
  bool isPointInTriangle(point_t a, point_t b, point_t c, point_t d);
  double getMyArea(point_t a, point_t b, point_t c);
}

bool dribas::isTriangle(point_t a, point_t b, point_t c)
{
  return !((((a.x_ == b.x_) && (a.x_ == c.x_))) || (( a.y_ == b.y_) && (a.y_ == c.y_)));
}

double dribas::getMyArea(point_t a, point_t b, point_t c) {
  return std::abs((a.x_ * (b.y_ - c.y_) + b.x_ * (c.y_ - a.y_) + c.x_ * (a.y_ -b.y_)) / 2.0l);
}

bool dribas::isPointInTriangle(point_t a, point_t b, point_t c, point_t d)
{
  double s = getMyArea(a, b, c);
  double s1 = getMyArea(a, b, d);
  double s2 = getMyArea(a, d, c);
  double s3 = getMyArea(d, b, c);
  return (s == (s1 + s2 + s3));
}

dribas::Concave::Concave(point_t a, point_t b, point_t c, point_t d):a_({0.0, 0.0}), b_({0.0, 0.0}), c_({0.0, 0.0}), d_({0.0, 0.0})
{
  if (!isTriangle(a, b, c) || !isPointInTriangle(a, b, c, d)) {
    throw std::invalid_argument("Error witch point for concave\n");
  }
  a_ = a;
  b_ = a;
  c_ = c;
  d_ = d;
}

double dribas::Concave::getArea() const
{
  return std::abs(a_.x_ * b_.y_ + b_.x_ * c_.y_ + c_.x_ * d_.y_ + d_.x_ * a_.y_ -
    b_.x_ * a_.y_ - c_.x_ * b_.y_ - d_.x_ * c_.y_ - a_.x_ * d_.y_) / 2.0l;
}
dribas::rectangle_t dribas::Concave::getFrameRect() const
{
  double maxX = std::max(a_.x_, std::max(b_.x_, std::max(c_.x_, d_.x_)));
  double maxY = std::max(a_.y_, std::max(b_.y_, std::max(c_.y_, d_.y_)));
  double minY = std::min(a_.y_, std::min(b_.y_, std::min(c_.y_, d_.y_)));
  double minX = std::min(a_.x_, std::min(b_.x_, std::min(c_.x_, d_.x_)));
  rectangle_t result;
  result.height_ = maxY - minY;
  result.width_ = maxX - minY;
  result.pos_.x_ = minX + (result.width_ / 2);
  result.pos_.y_ = maxX + (result.height_ / 2);
  return result;
}
void dribas::Concave::move(double x, double y)
{
  a_.x_ += x;
  b_.x_ += x;
  c_.x_ += x;
  d_.x_ += x;
  a_.y_ += y;
  b_.y_ += y;
  c_.y_ += y;
  d_.y_ += y;
}

void dribas::Concave::move(point_t point)
{
  double moveX = point.x_ - d_.x_;
  double moveY = point.y_ - d_.y_;
  move(moveX, moveY);
}

void dribas::Concave::scale(double ratio)
{
  if (ratio <= 0) {
    throw std::invalid_argument("under zero ratio\n");
  }
  if (a_.x_ - d_.x_ < 0) {
    a_.x_ = -(d_.x_ - a_.x_) * ratio;
  } else {
    a_.x_ = (a_.x_ - d_.x_) * ratio;
  }
  if (b_.x_ - d_.x_ < 0) {
    b_.x_ = -(d_.x_ - b_.x_) * ratio;
  } else {
    b_.x_ = (b_.x_ - d_.x_) * ratio;
  }
  if (c_.x_ - d_.x_ < 0) {
    c_.x_ = -(d_.x_ - c_.x_) * ratio;
  } else {
    c_.x_ = (c_.x_ - d_.x_) * ratio;
  }
   if (a_.y_ - d_.y_ < 0) {
    a_.y_ = -(d_.y_ - a_.y_) * ratio;
  } else {
    a_.y_ = (a_.y_ - d_.y_) * ratio;
  }
  if (b_.y_ - d_.y_ < 0) {
    b_.y_ = -(d_.y_ - b_.y_) * ratio;
  } else {
    b_.y_ = (b_.y_ - d_.y_) * ratio;
  }
  if (c_.y_ - d_.y_ < 0) {
    c_.y_ = -(d_.y_ - c_.y_) * ratio;
  } else {
    c_.y_ = (c_.y_ - d_.y_) * ratio;
  }
}
