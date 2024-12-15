#include "square.h"
#include <stdexcept>
namespace cherkasov
{
  Square::Square(point_t lowLeft, double leght)
  {
    if (leght <= 0)
    {
      throw std::logic_error("leght must positiv");
    }
    square_.pos = {lowLeft.x + leght / 2, lowLeft.y + leght / 2};
    square_.width = leght;
    square_.height = leght;
  }
  double Square::getArea() const
  {
    return square_.width * square_.height;
  }
  rectangle_t Square::getFrameRect() const
  {
    return square_;
  }
  void Square::move(point_t c)
  {
    square_.pos = c;
  }
  void Square::move(double dx, double dy)
  {
    square_.pos.x += dx;
    square_.pos.y += dy;
  }
  void Square::scale(double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("scale factor must positive");
    }
  square_.width *= k;
  square_.height *= k;
  }
}
