#include "rectangle.hpp"
#include <cmath>
#include <algorithm>

namespace cherkasov
{
  Rectangle::Rectangle(double x1, double y1, double x2, double y2)
  {
    left.x = std::min(x1, x2);
    left.y = std::min(y1, y2);
    right.x = std::max(x1, x2);
    right.y = std::max(y1, y2);
  }
  double Rectangle::getArea() const
  {
    double width = std::abs(right.x - left.x);
    double height = std::abs(right.y - left.y);
    return width * height;
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    point_t center{};
    center.x = (left.x + right.x) / 2.0;
    center.y = (left.y + right.y) / 2.0;
    rectangle_t rect{};
    rect.width = std::abs(right.x - left.x);
    rect.height = std::abs(right.y - left.y);
    rect.pos = center;
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
    left.x = center.x + (left.x - center.x) * k;
    left.y = center.y + (left.y - center.y) * k;
    right.x = center.x + (right.x - center.x) * k;
    right.y = center.y + (right.y - center.y) * k;
  }
}
