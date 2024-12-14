#include "rectangle.hpp"

namespace kushekbaev
{
  Rectangle::Rectangle(point_t lowerLeft, point_t upperRight) : lowerLeft_(lowerLeft), upperRight_(upperRight)
  {
  }

  double Rectangle::getArea() const
  {
    double area = ((upperRight_.x - lowerLeft_.x) * (upperRight_.y - lowerLeft_.y));
    return area;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return { upperRight_.x - lowerLeft_.x, upperRight_.y - lowerLeft_.y, { lowerLeft_.x + (upperRight_.x - lowerLeft_.x) / 2, lowerLeft_.y + (upperRight_.y - lowerLeft_.y) / 2 } };
  }

  void Rectangle::move(point_t Z)
  {
    point_t middle = this->getFrameRect().pos;
    double moveX = Z.x - middle.x;
    double moveY = Z.y - middle.y;
    lowerLeft_.x += moveX;
    lowerLeft_.y += moveY;
    upperRight_.x += moveX;
    upperRight_.y += moveY;
  }

  void Rectangle::move(double dy, double dx)
  {
    lowerLeft_.x += dx;
    upperRight_.x += dx;
    lowerLeft_.y += dy;
    upperRight_.y += dy;
  }

  void Rectangle::scale(double V)
  {
    point_t middle = getFrameRect().pos;
    lowerLeft_.x = (lowerLeft_.x - middle.x) * V + middle.x;
    upperRight_.x = (upperRight_.x - middle.x) * V + middle.x;
    lowerLeft_.y = (lowerLeft_.y - middle.y) * V + middle.y;
    upperRight_.y = (upperRight_.y - middle.y) * V + middle.y;
  }
}
