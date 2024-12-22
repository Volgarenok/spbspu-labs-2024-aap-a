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
    center.x = (x1 + x2) / 2;
    center.y = (y1 + y2) / 2;
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
    rect.pos = center;
    return rect;
  }
  void Rectangle::move(point_t c)
  {
    point_t center = getFrameRect().pos;
    double moveX = c.x - center.x;
    double moveY = c.y - center.y;
    left_.x += moveX;
    right_.x += moveX;
    left_.y += moveY;
    right_.y += moveY;
    center.x = c.x;
    center.y = c.y;
  }
  void Rectangle::move(double dx, double dy)
  {
    left_.x += dx;
    right_.x += dx;
    left_.y += dy;
    right_.y += dy;
    center.x = dx;
    center.y = dy;
  }
  void Rectangle::scale(double k)
  {
    left_.x = center.x - (center.x - left_.x) * k;
    right_.x = center.x + (right_.x - center.x) * k;
    left_.y = center.y - (center.y - left_.y) * k;
    right_.y = center.y + (right_.y - center.y) * k;
  }
}
