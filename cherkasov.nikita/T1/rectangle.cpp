#include "rectangle.h"
#include <cmath>
#include <algorithm>

namespace cherkasov
{
  Rectangle:: Rectangle(double x1, double y1, double x2, double y2)
  {
    left.x = std::min(x1, x2);
    left.y = std::min(y1, y2);
    right.x = std::max(x1, x2);
    right.y = std::max(y1, y2);
  }
  double Rectangle::getArea() const
  {
    return std::abs((right.x - left.x) * (right.y - left.y));
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    rectangle_t rect;
    rect.width = std::abs(right.x - left.x);
    rect.height = std::abs(right.y - left.y);
    rect.pos.x = (left.x + right.x) / 2.0;
    rect.pos.y = (left.y + right.y) / 2.0;
    return rect;
  }
  void Rectangle::move(point_t c)
  {
    point_t Pos = getFrameRect().pos;
    double moveX = c.x - Pos.x;
    double moveY = c.y - Pos.y;
    left.x += moveX;
    right.x += moveX;
    left.y += moveY;
    right.y += moveY;
  }
  void Rectangle::move(double dx, double dy)
  {
    left.x += dx;
    right.x += dx;
    left.y += dy;
    right.y += dy;
  }
  void Rectangle::scale(double k)
  {
    point_t center = getFrameRect().pos;
    rectangle_t rect;
    rect.width = (right.x - left.x) * k;
    rect.height = (right.y - left.y) * k;
    left.x = center.x - rect.width / 2.0;
    right.x = center.x + rect.width / 2.0;
    left.y = center.y - rect.height / 2.0;
    right.y = center.y + rect.height / 2.0;
  }
}
