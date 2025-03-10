#include "rectangle.hpp"

namespace belobrov
{
  Rectangle::Rectangle(double x1, double y1, double x2, double y2)
  {
    lowerLeft_.x = x1;
    lowerLeft_.y = y1;
    upperRight_.x = x2;
    upperRight_.y = y2;
  }
  double Rectangle::getArea() const
  {
    return (upperRight_.x - lowerLeft_.x) * (upperRight_.y - lowerLeft_.y);
  }
  rectangle_t Rectangle::getFrameRect() const
  {
    rectangle_t frameRect;
    frameRect.height = upperRight_.y - lowerLeft_.y;
    frameRect.width = upperRight_.x - lowerLeft_.x;
    frameRect.pos.x = lowerLeft_.x + (frameRect.width / 2);
    frameRect.pos.y = lowerLeft_.y + (frameRect.height / 2);
    return frameRect;
  }
  void Rectangle::move(point_t newPos)
  {
    point_t currentPos = getFrameRect().pos;
    double moveX = newPos.x - currentPos.x;
    double moveY = newPos.y - currentPos.y;
    lowerLeft_.x += moveX;
    upperRight_.x += moveX;
    lowerLeft_.y += moveY;
    upperRight_.y += moveY;
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
    point_t currentPos = getFrameRect().pos;
    lowerLeft_.x = currentPos.x - (currentPos.x - lowerLeft_.x) * k;
    upperRight_.x = currentPos.x + (upperRight_.x - currentPos.x) * k;
    lowerLeft_.y = currentPos.y - (currentPos.y - lowerLeft_.y) * k;
    upperRight_.y = currentPos.y + (upperRight_.y - currentPos.y) * k;
  }
}
