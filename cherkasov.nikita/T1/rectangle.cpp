#include "rectangle.h"
#include <stdexcept>

namespace cherkasov
{
  Rectangle::Rectangle(point_t lowLeft, point_t upRight)
  : rect({(lowLeft.x + upRight.x) / 2, (lowLeft.y + upRight.y) / 2, upRight.x - lowLeft.x, upRight.y - lowLeft.y})
  {}
  double Rectangle::getArea() const
  {
    return rect.width * rect.height;
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    return rect;
  }
  void Rectangle::move(point_t c)
  {
    rect.pos = c;
  }
  void Rectangle::move(double dx, double dy)
  {
    rect.pos.x += dx;
    rect.pos.y += dy;
  }
  void Rectangle::scale(double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("Scale factor must be positive");
    }
    rect.width *= k;
    rect.height *= k;
  }
}
