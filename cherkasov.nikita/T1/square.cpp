#include "square.hpp"
#include "shapeUtils.hpp"
#include <stdexcept>
#include <cmath>

namespace cherkasov
{
  Square::Square(point_t left, double length):
    left(left),
    length(length)
    {
      if (length <= 0)
      {
        throw std::invalid_argument("no input coordinate square");
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
    double dx = c.x - currentPos.x;
    double dy = c.y - currentPos.y;
    move(dx, dy);
  }
  void Square::move(double dx, double dy)
  {
    moveVertex(left, dx, dy);
  }
  void Square::scalingFactor(double k)
  {
    point_t currentPos = getFrameRect().pos;
    length *= k;
    scalePoint(left, currentPos, k);
  }
}
