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
    return std::abs((right_.x - left_.x) * (right_.y - left_.y));
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    rectangle_t rect;
    rect.height = std::abs(right_.y - left_.y);
    rect.width = std::abs(right_.x - left_.x);
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
    point_t center = getFrameRect().pos;
    left_.x = center.x + (left_.x - center.x) * k;
    right_.x = center.x + (right_.x - center.x) * k;
    left_.y = center.y + (left_.y - center.y) * k;
    right_.y = center.y + (right_.y - center.y) * k;
  }
}
