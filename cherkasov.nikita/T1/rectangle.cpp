#include "rectangle.hpp"
#include "shapeUtils.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace cherkasov
{
  Rectangle::Rectangle(double x1, double y1, double x2, double y2)
  : left(left),
    right(right)
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
    double width = right.x - left.x;
    double height = right.y - left.y;
    return width * height;
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    point_t center{};
    center.x = (left.x + right.x) / 2.0;
    center.y = (left.y + right.y) / 2.0;
    rectangle_t rect{right.x - left.x, right.y - left.y, center};
    return rect;
  }
  void Rectangle::move(point_t c)
  {
    point_t currentPos = getFrameRect().pos;
    double dx = c.x - currentPos.x;
    double dy = c.y - currentPos.y;
    move(dx, dy);
  }
  void Rectangle::move(double dx, double dy)
  {
    moveVertex(left, dx, dy);
    moveVertex(right, dx, dy);
  }
  void Rectangle::scale(double k)
  {
    point_t center = getFrameRect().pos;
    scalePoint(left, center, k);
    scalePoint(right, center, k);
  }
}
