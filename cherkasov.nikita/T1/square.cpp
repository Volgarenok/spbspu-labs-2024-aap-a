#include "square.h"
#include <stdexcept>
namespace cherkasov
{
  Square::Square(point_t lowLeft, double lenght)
  {
    if (lenght <= 0)
    {
      throw std::logic_error("leght must positiv");
    }
    square.pos = {lowLeft.x + lenght / 2, lowLeft.y + lenght / 2};
    square.width = lenght;
    square.height = lenght;
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
      throw std::logic_error("scale factor must positive");
    }
  square.width *= k;
  square.height *= k;
  }
}
