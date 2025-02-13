#include "square.hpp"
#include <stdexcept>
#include <cmath>

namespace cherkasov
{
  Square::Square(double x1, double y1, double length)
  : left {x1, y1},
    length(length)
    {
      if (length <= 0)
      {
        throw std::invalid_argument("no input coordinate");
      }
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
    point_t currentPos = getFrameRect().pos;
    double moveX = c.x - currentPos.x;
    double moveY = c.y - currentPos.y;
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
    if (k < 0)
    {
      throw std::invalid_argument("k must be positive");
    }
    point_t currentPos = getFrameRect().pos;
    length *= k;
    left.x = currentPos.x - (length / 2);
    left.y = currentPos.y - (length / 2);
  }
}
