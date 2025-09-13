#include "rectangle.hpp"
#include <stdexcept>

namespace cherkasov
{
  Rectangle::Rectangle(point_t left, point_t right):
    parallelogram({ left.x, left.y }, { right.x, left.y }, { right.x, right.y })
      {
        if ((left.x >= right.x || left.y >= right.y) || (left.x == right.x || left.y == right.y))
        {
          throw std::invalid_argument("incorrect coordinats");
        }
      }
  double Rectangle::getArea() const
  {
    return parallelogram.getArea();
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    return parallelogram.getFrameRect();
  }
  void Rectangle::move(point_t p)
  {
    parallelogram.move(p);
  }
  void Rectangle::move(double dx, double dy)
  {
    parallelogram.move(dx, dy);
  }
  void Rectangle::scalingFactor(double k)
  {
    parallelogram.scalingFactor(k);
  }
}
