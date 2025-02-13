#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace cherkasov
{
  Rectangle::Rectangle(double x1, double y1, double x2, double y2)
  : left {std::min(x1, x2), std::min(y1, y2)},
    right {std::max(x1, x2), std::max(y1, y2)}
    {
      if (x1 >= x2 || y1 >= y2)
      {
        throw std::invalid_argument("no input coordinate");
      }
    }
  double Rectangle::getArea() const
  {
    double width = right.x - left.x;
    double height = right.y - left.y;
    return width * height;
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    point_t center{};
    center.x = (left.x + right.x) / 2.0;
    center.y = (left.y + right.y) / 2.0;
    rectangle_t rect{right.x - left.x, right.y - left.y, center};
    return rect;
  }
  void Rectangle::move(point_t c)
  {
    point_t currentPos = getFrameRect().pos;
    double moveX = c.x - currentPos.x;
    double moveY = c.y - currentPos.y;
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
    if (k < 0)
    {
      throw std::invalid_argument("k must be positive");
    }
    point_t center = getFrameRect().pos;
    left.x = center.x + (left.x - center.x) * k;
    left.y = center.y + (left.y - center.y) * k;
    right.x = center.x + (right.x - center.x) * k;
    right.y = center.y + (right.y - center.y) * k;
  }
}
