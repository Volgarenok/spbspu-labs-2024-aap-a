#include "rectangle.hpp"
#include "base-types.hpp"
#include <stdexcept>

namespace kushekbaev
{
  Rectangle::Rectangle(point_t lowerLeft, point_t upperRight) : lowerLeft_(lowerLeft), upperRight_(upperRight)
  {
  }

  double Rectangle::getArea() const
  {
    return (upperRight_.x - lowerLeft_.x) * (upperRight_.y - lowerLeft_.y);
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    double middleForX = lowerLeft_.x + (upperRight_.x - lowerLeft_.x) / 2;
    double middleForY = lowerLeft_.y + (upperRight_.y - lowerLeft_.y) / 2;
    return { upperRight_.x - lowerLeft_.x, upperRight_.y - lowerLeft_.y, { middleForX, middleForY } };
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

  void Rectangle::move(double dx, double dy)
  {
    lowerLeft_.x += dx;
    lowerLeft_.y += dy;
    upperRight_.x += dx;
    upperRight_.y += dy;
  }

  void Rectangle::scale(double V)
  {
    if (V <= 0)
    {
      throw std::invalid_argument("Scale coefficient should be greater than zero\n");
    }
    point_t middle = this->getFrameRect().pos;
    lowerLeft_.x = middle.x + (lowerLeft_.x - middle.x) * V;
    lowerLeft_.y = middle.y + (lowerLeft_.y - middle.y) * V;
    upperRight_.x = middle.x + (upperRight_.x - middle.x) * V;
    upperRight_.y = middle.y + (upperRight_.y - middle.y) * V;
  }
}
