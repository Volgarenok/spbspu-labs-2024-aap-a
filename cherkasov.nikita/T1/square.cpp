#include "square.hpp"
#include <cmath>

namespace cherkasov
{
  Square::Square(double x1, double y1, double length)
    : left {x1, y1}, length(length)
  {
    left.x = x1;
    left.y = y1;
    length = length;
  }
  double Square::getArea() const
  {
    return length * length;
  }
  rectangle_t Square::getFrameRect() const
  {
    rectangle_t rect{};
    rect.height = length;
    rect.width = length;
    rect.pos.y = left.y + (length / 2);
    rect.pos.x = left.x + (length / 2);
    return rect;
  }
  void Square::move(point_t c)
  {
    point_t Pos = getFrameRect().pos;
    double moveX = c.x - Pos.x;
    double moveY = c.y - Pos.y;
    left.x += moveX;
    left.y += moveY;
  }
  void Square::move(double dx, double dy)
  {
    left.x += dx;
    left.y += dy;
  }
  void Square::scale(double k)
  {
    point_t Pos = getFrameRect().pos;
    length *= k;
    left.x = Pos.x - (length / 2);
    left.y = Pos.y - (length / 2);
  }
}
