#include "rectangle.hpp"
#include <cmath>

namespace maslovskiy
{
  Rectangle::Rectangle(point_t leftCorner, point_t rightCorner)
      : leftCorner_(leftCorner), rightCorner_(rightCorner)
  {}

  double Rectangle::getArea() const
  {
    return std::abs(leftCorner_.x - rightCorner_.x) * std::abs(leftCorner_.y - rightCorner_.y);
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    double width = std::abs(leftCorner_.x - rightCorner_.x);
    double height = std::abs(leftCorner_.y - rightCorner_.y);
    point_t pos = {leftCorner_.x + width / 2, leftCorner_.y + height / 2};
    return rectangle_t{width, height, pos};
  }

  void Rectangle::move(point_t newPos)
  {
    point_t currentCenter = getFrameRect().pos;
    double moveX = newPos.x - currentCenter.x;
    double moveY = newPos.y - currentCenter.y;
    leftCorner_.x += moveX;
    leftCorner_.y += moveY;
    rightCorner_.x += moveX;
    rightCorner_.y += moveY;
  }

  void Rectangle::move(double moveX, double moveY)
  {
    leftCorner_.x += moveX;
    leftCorner_.y += moveY;
    rightCorner_.x += moveX;
    rightCorner_.y += moveY;
  }

  void Rectangle::scale(double factor)
  {
    point_t currentCenter = getFrameRect().pos;
    leftCorner_.x = currentCenter.x - (currentCenter.x - leftCorner_.x) * factor;
    leftCorner_.y = currentCenter.y - (currentCenter.y - leftCorner_.y) * factor;
    rightCorner_.x = currentCenter.x - (currentCenter.x - rightCorner_.x) * factor;
    rightCorner_.y = currentCenter.y - (currentCenter.y - rightCorner_.y) * factor;
  }
}
