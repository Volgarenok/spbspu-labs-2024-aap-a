#include "rectangle.hpp"
#include <stdexcept>
namespace maslovskiy
{
  Rectangle::Rectangle(point_t leftCorner, point_t rightCorner)
      : leftCorner_(leftCorner), rightCorner_(rightCorner)
  {
    if ((leftCorner.x > leftCorner.y || rightCorner.x > rightCorner.y))
    {
      throw std::logic_error("Incorrect rectangle points");
    }
  }
  double Rectangle::getArea() const
  {
    return ((leftCorner_.x - rightCorner_.x) * (leftCorner_.y - rightCorner_.y));
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    double width = leftCorner_.x - rightCorner_.x;
    double height = leftCorner_.y - rightCorner_.y;
    point_t pos = {leftCorner_.x - (width / 2), leftCorner_.y - (height / 2)};
    rectangle_t frameRect{width, height, pos};
    return frameRect;
  }
  void Rectangle::move(double dx, double dy)
  {
    leftCorner_.x += dx;
    leftCorner_.y += dy;
    rightCorner_.x += dx;
    rightCorner_.y += dy;
  }
  void Rectangle::move(point_t newPos)
  {
    rectangle_t rect = getFrameRect();
    double dx = rect.pos.x - newPos.x;
    double dy = rect.pos.y - newPos.y;
    move(dx, dy);
  }
  void maslovskiy::Rectangle::scale(double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("Scaling coefficient must be positive");
    }
    double newWidth = (leftCorner_.x - rightCorner_.x) * k;
    double newHeigth = (leftCorner_.y - rightCorner_.y) * k;
    point_t center = getFrameRect().pos;
    rightCorner_.x = center.x + newWidth / 2;
    rightCorner_.y = center.y + newHeigth / 2;
    leftCorner_.x = center.x - newWidth / 2;
    leftCorner_.y = center.y - newHeigth / 2;
  }
}
