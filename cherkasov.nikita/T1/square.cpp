#include "square.hpp"
#include <stdexcept>

namespace cherkasov
{
  Square::Square(point_t left, double length):
    parallelogram(left, { left.x + length, left.y }, { left.x + length, left.y + length })
    {
      if (length <= 0)
      {
        throw std::invalid_argument("no input coordinate square");
      }
    }
  double Square::getArea() const
  {
    return parallelogram.getArea();
  }
  rectangle_t Square::getFrameRect() const
  {
    return parallelogram.getFrameRect();
  }
  void Square::move(point_t c)
  {
    return parallelogram.move(c);
  }
  void Square::move(double dx, double dy)
  {
    return parallelogram.move(dx, dy);
  }
  void Square::scalingFactor(double k)
  {
    return parallelogram.scalingFactor(k);
  }
}
