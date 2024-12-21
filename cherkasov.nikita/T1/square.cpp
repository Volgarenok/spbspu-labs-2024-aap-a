#include "square.h"
#include <stdexcept>

namespace cherkasov
{
  Square::Square(point_t lowLeft, double length)
  {
    if (length <= 0)
    {
      throw std::logic_error("Length must be positive");
    }
    square.pos = {lowLeft.x + length / 2, lowLeft.y + length / 2};
    square.width = length;
    square.height = length;
  }
  double Square::getArea() const
  {
    return square.width * square.height;
  }
  rectangle_t Square::getFrameRect() const
  {
    return square;
  }
  void Square::move(point_t c)
  {
    square.pos = c;
  }
  void Square::move(double dx, double dy)
  {
    square.pos.x += dx;
    square.pos.y += dy;
  }
  void Square::scale(double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("Scale factor must be positive");
    }
    square.width *= k;
    square.height *= k;
  }
}
