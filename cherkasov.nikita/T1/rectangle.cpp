#include "rectangle.h"
#include <stdexcept>
namespace cherkasov
{
  Rectangle::Rectangle(point_t lowLeft, point_t upRight)
  {
    if (lowLeft.x >= upRight.x || lowLeft.y >= upRight.y)
    {
      throw std::logic_error("invalid rectangl coordinates");
    }
  rect_.pos = {(lowLeft.x + upRight.x) / 2, (lowLeft.y + upRight.y) / 2};
  rect_.width = upRight.x - lowLeft.x;
  rect_.height = upRight.y - lowLeft.y;
  }

  double Rectangle::getArea() const
  {
    return rect_.width * rect_.height;
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    return rect_;
  }
  void Rectangle::move(point_t c)
  {
    rect_.pos = c;
  }
  void Rectangle::move(double dx, double dy)
  {
    rect_.pos.x += dx;
    rect_.pos.y += dy;
  }
  void Rectangle::scale(double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("dddd");
    }
  rect_.width *= k;
  rect_.height *= k;
  }
}

