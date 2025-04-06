#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>
#include "shapeUtils.hpp"

namespace cherkasov
{
  Rectangle::Rectangle(point_t left, point_t right):
    parallelogram(left, { right.x, left.y }, { left.x, right.y })
    {
      if (left.x >= right.x || left.y >= right.y)
      {
        throw std::invalid_argument("incorrect coordinats");
      }
      if (left.x == right.x || left.y == right.y)
      {
        throw std::invalid_argument("coordinats must not match");
      }
    }
  double Rectangle::getArea() const
  {
    /*double width = right.x - left.x;
    double height = right.y - left.y;
    return width * height;*/
    return parallelogram.getArea();
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    /*point_t center{};
    center.x = (left.x + right.x) / 2.0;
    center.y = (left.y + right.y) / 2.0;
    rectangle_t rect { right.x - left.x, right.y - left.y, center };
    return rect;*/
    return parallelogram.getFrameRect();
  }
  void Rectangle::move(point_t p)
  {
    /*point_t currentPos = getFrameRect().pos;
    double dx = c.x - currentPos.x;
    double dy = c.y - currentPos.y;
    move(dx, dy);*/
    parallelogram.move(p);
  }
  void Rectangle::move(double dx, double dy)
  {
    /*moveVertex(left, dx, dy);
    moveVertex(right, dx, dy);*/
    parallelogram.move(dx, dy);
  }
  void Rectangle::scalingFactor(double k)
  {
    /*point_t center = getFrameRect().pos;
    scalePoint(left, center, k);
    scalePoint(right, center, k);*/
    parallelogram.scalingFactor(k);
  }
}
