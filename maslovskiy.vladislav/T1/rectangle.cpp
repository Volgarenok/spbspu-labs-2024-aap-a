#include "rectangle.hpp"
#include <cmath>

namespace maslovskiy
{
  Rectangle::Rectangle(double x1, double y1, double x2, double y2)
  {
    leftCorner_.x = x1;
    leftCorner_.y = y1;
    rightCorner_.x = x2;
    rightCorner_.y = y2;
  }
  double Rectangle::getArea() const
  {
    return (rightCorner_.x - leftCorner_.x) * (rightCorner_.y - leftCorner_.y);
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    rectangle_t frameRect;
    frameRect.height = rightCorner_.y - leftCorner_.y;
    frameRect.width = rightCorner_.x - leftCorner_.x;
    frameRect.pos.x = leftCorner_.x + (frameRect.width / 2);
    frameRect.pos.y = leftCorner_.y + (frameRect.height / 2);
    return frameRect;
  }
  void Rectangle::move(point_t newPos)
  {
    point_t currentPos = getFrameRect().pos;
    double moveX = newPos.x - currentPos.x;
    double moveY = newPos.y - currentPos.y;
    leftCorner_.x += moveX;
    rightCorner_.x += moveX;
    leftCorner_.y += moveY;
    rightCorner_.y += moveY;
  }
  void Rectangle::move(double dx, double dy)
  {
    leftCorner_.x += dx;
    rightCorner_.x += dx;
    leftCorner_.y += dy;
    rightCorner_.y += dy;
  }
  void Rectangle::scale(double k)
  {
    point_t currentPos = getFrameRect().pos;
    leftCorner_.x = currentPos.x - (currentPos.x - leftCorner_.x) * k;
    rightCorner_.x = currentPos.x + (rightCorner_.x - currentPos.x) * k;
    leftCorner_.y = currentPos.y - (currentPos.y - leftCorner_.y) * k;
    rightCorner_.y = currentPos.y + (rightCorner_.y - currentPos.y) * k;
  }
}
