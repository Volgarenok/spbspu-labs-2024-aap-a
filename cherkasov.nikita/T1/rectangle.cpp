#include "rectangle.h"
#include <cmath>

namespace cherkasov
{
  Rectangle:: Rectangle(double x1, double y1, double x2, double y2)
  {
    left_.x = x1;
    left_.y = y1;
    right_.x = x2;
    right_.y = y2;
  }
  double Rectangle::getArea() const
  {
    return (right_.x - left_.x) * (right_.y - left_.y);
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    rectangle_t rect;
    rect.height = right_.y - left_.y;
    rect.width = right_.x - left_.x;
    rect.pos.y = left_.y + (rect.height / 2);
    rect.pos.x = left_.x + (rect.width / 2);
    return rect;
  }
  void Rectangle::move(point_t c)
  {
    point_t Pos = getFrameRect().pos;
    double moveX = c.x - Pos.x;
    double moveY = c.y - Pos.y;
    left_.x += moveX;
    right_.x += moveX;
    left_.y += moveY;
    right_.y += moveY;
  }
  void Rectangle::move(double dx, double dy)
  {
    left_.x += dx;
    right_.x += dx;
    left_.y += dy;
    right_.y += dy;
  }
  void Rectangle::scale(double k)
  {
    point_t Pos = getFrameRect().pos;
    left_.x = Pos.x - (Pos.x - left_.x) * k;
    right_.x = Pos.x + (right_.x - Pos.x) * k;
    left_.y = Pos.y - (Pos.y - left_.y) * k;
    right_.y = Pos.y + (right_.y - Pos.y) * k;
  }
}
