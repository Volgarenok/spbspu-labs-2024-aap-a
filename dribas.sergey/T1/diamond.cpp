#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

dribas::Diamond::Diamond(point_t a, point_t b, point_t c): a_({0.0, 0.0}), b_({0.0, 0.0}), c_({0.0, 0.0})
{
  if ((a.x_ == b.x_ && a.y_ == c.y_) || (a.y_ == b.y_ && a.x_ == c.x_)) {
    a_ = a;
    if (a_.x_ == b.x_) {
      b_ = b;
      c_ = c;
    } else {
      b_ = c;
      c_ = b;
    }
  } else if ((b.x_ == a.x_ && b.y_ == c.y_) || (b.y_ == a.y_ && b.x_ == c.x_)) {
    a_ = b;
    if (a_.x_ == a.x_) {
      b_ = a;
      c_ = c;
    } else {
      b_ = c;
      c_ = a;
    }

  } else if ((c.x_ == b.x_ && c.y_ == a.y_) || (c.y_ == b.y_ && c.x_ == a.x_)) {
    a_ = c;
    if (a_.x_ == b.x_) {
      b_ = b;
      c_ = a;
    } else {
      b_ = a;
      c_ = b;
    }
  } else {
    throw std::invalid_argument("error with rectangle size\n");
  }
}
double dribas::Diamond::getArea() const
{
  return std::abs(a_.x_ - b_.x_ + a_.x_ - c_.x_) * std::abs(a_.y_ - b_.y_ + a_.y_ - c_.y_) * 2.0L ;
}

dribas::rectangle_t dribas::Diamond::getFrameRect() const
{
  rectangle_t fremRECT;
  fremRECT.pos_ = a_;
  fremRECT.width_ = std::max(std::abs(c_.x_ - a_.x_), std::abs(b_.x_ - a_.x_));
  fremRECT.height_ = std::max(std::abs(c_.y_ - a_.y_), std::abs(b_.y_ - a_.y_));
  return fremRECT;
}

void dribas::Diamond::move(double x, double y)
{
  a_.y_ += y;
  a_.x_ += x;
  b_.x_ += x;
  b_.y_ += y;
  c_.x_ += x;
  c_.y_ += y;
}

void dribas::Diamond::move(point_t point)
{
  double moveX = point.x_ - a_.x_;
  double moveY = point.y_ - a_.y_;
  move(moveX, moveY);
}
void dribas::Diamond::scale(double ratio)
{
  if (ratio <= 0) {
    throw std::invalid_argument("under zero ratio\n");
  }
  b_.x_ = (b_.x_ - a_.x_) * ratio;
  c_.y_ = (c_.y_ - a_.y_) * ratio;
}
