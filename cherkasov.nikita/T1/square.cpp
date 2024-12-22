#include "square.h"
#include <cmath>

namespace cherkasov
{
  Square::Square(double x1, double y1, double length)
  {
    left_.x = x1;
    left_.y = y1;
    length_ = length;
  }
  double Square::getArea() const
  {
    return length_ * length_;
  }
  rectangle_t Square::getFrameRect() const
  {
    rectangle_t rect;
    rect.height = length_;
    rect.width = length_;
    rect.pos.y = left_.y + (length_ / 2);
    rect.pos.x = left_.x + (length_ / 2);
    return rect;
  }
  void Square::move(point_t c)
  {
    point_t Pos = getFrameRect().pos;
    double moveX = c.x - Pos.x;
    double moveY = c.y - Pos.y;
    left_.x += moveX;
    left_.y += moveY;
  }
  void Square::move(double dx, double dy)
  {
    left_.x += dx;
    left_.y += dy;
  }
  void Square::scale(double k)
  {
    point_t center = getFrameRect().pos;
    length_ *= k;
    left_.x = center.x - length_ / 2;
    left_.y = center.y - length_ / 2;
  }
}
