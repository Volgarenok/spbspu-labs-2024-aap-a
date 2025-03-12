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
    point_t center = { (lowerLeft_.x + upperRight_.x) / 2, (lowerLeft_.y + upperRight_.y) / 2 };
    lowerLeft_.x = center.x + (lowerLeft_.x - center.x) * k;
    lowerLeft_.y = center.y + (lowerLeft_.y - center.y) * k;
    upperRight_.x = center.x + (upperRight_.x - center.x) * k;
    upperRight_.y = center.y + (upperRight_.y - center.y) * k;
  }
}
