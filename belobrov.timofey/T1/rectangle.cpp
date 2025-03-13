#include "rectangle.hpp"
#include <cmath>

namespace belobrov
{
  Rectangle::Rectangle(const point_t& lowerLeft, const point_t& upperRight)
    : lowerLeft_(lowerLeft), upperRight_(upperRight) {}

  double Rectangle::getArea() const
  {
    return std::abs((upperRight_.x - lowerLeft_.x) * (upperRight_.y - lowerLeft_.y));
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return {
      std::abs(upperRight_.x - lowerLeft_.x),
      std::abs(upperRight_.y - lowerLeft_.y),
      { (lowerLeft_.x + upperRight_.x) / 2, (lowerLeft_.y + upperRight_.y) / 2 }
    };
  }

  void Rectangle::move(const point_t& newPos)
  {
    point_t center = { (lowerLeft_.x + upperRight_.x) / 2, (lowerLeft_.y + upperRight_.y) / 2 };
    double dx = newPos.x - center.x;
    double dy = newPos.y - center.y;
    move(dx, dy);
  }

  void Rectangle::move(double dx, double dy)
  {
    lowerLeft_.x += dx;
    upperRight_.x += dx;
    lowerLeft_.y += dy;
    upperRight_.y += dy;
  }

  void Rectangle::scale(double k)
  {
    double centerX = (x1 + x2) / 2.0;
    double centerY = (y1 + y2) / 2.0;

    x1 = centerX + (x1 - centerX) * k;
    y1 = centerY + (y1 - centerY) * k;
    x2 = centerX + (x2 - centerX) * k;
    y2 = centerY + (y2 - centerY) * k;
  }
}
