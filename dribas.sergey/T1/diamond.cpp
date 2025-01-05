#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

dribas::Diamond::Diamond(point_t a, point_t b, point_t c):
  a_({0.0, 0.0}),
  b_({0.0, 0.0}),
  c_({0.0, 0.0})
{
  if ((a.x == b.x && a.y == c.y) || (a.y == b.y && a.x == c.x)) {
    a_ = a;
    if (a_.x == b.x) {
      b_ = b;
      c_ = c;
    } else {
      b_ = c;
      c_ = b;
    }
  } else if ((b.x == a.x && b.y == c.y) || (b.y == a.y && b.x == c.x)) {
    a_ = b;
    if (a_.x == a.x) {
      b_ = a;
      c_ = c;
    } else {
      b_ = c;
      c_ = a;
    }

  } else if ((c.x == b.x && c.y == a.y) || (c.y == b.y && c.x == a.x)) {
    a_ = c;
    if (a_.x == b.x) {
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
  return std::abs(a_.x - b_.x + a_.x - c_.x) * std::abs(a_.y - b_.y + a_.y - c_.y) * 2.0L ;
}

dribas::rectangle_t dribas::Diamond::getFrameRect() const
{
  rectangle_t fremRECT;
  fremRECT.pos = a_;
  fremRECT.width = std::abs(c_.x - a_.x) * 2;
  fremRECT.height = std::abs(b_.y - a_.y) * 2;
  return fremRECT;
}

void dribas::Diamond::move(double x, double y)
{
  a_.y += y;
  a_.x += x;
  b_.x += x;
  b_.y += y;
  c_.x += x;
  c_.y += y;
}

void dribas::Diamond::move(point_t point)
{
  double moveX = point.x - a_.x;
  double moveY = point.y - a_.y;
  move(moveX, moveY);
}
void dribas::Diamond::scale(double ratio)
{
  if (ratio <= 0) {
    throw std::invalid_argument("under zero ratio\n");
  }
  b_.y = (a_.y - b_.y) * ratio + a_.y;
  c_.x = (a_.x - c_.x) * ratio + a_.x;
}
