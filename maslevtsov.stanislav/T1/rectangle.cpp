#include "rectangle.hpp"
#include <stdexcept>

maslevtsov::Rectangle::Rectangle(point_t bottomLeft, point_t topRight)
{
  if (topRight.x <= bottomLeft.x || topRight.y <= bottomLeft.y)
  {
    throw std::logic_error("incorrect coordinates");
  }
  bottomLeft_ = bottomLeft;
  topRight_ = topRight;
}

double maslevtsov::Rectangle::getArea() const noexcept
{
  return (topRight_.x - bottomLeft_.x) * (topRight_.y - bottomLeft_.y);
}

maslevtsov::rectangle_t maslevtsov::Rectangle::getFrameRect() const noexcept
{
  rectangle_t frameRect;
  frameRect.width = topRight_.x - bottomLeft_.x;
  frameRect.height = topRight_.y - bottomLeft_.y;
  frameRect.pos.x = frameRect.width / 2 + bottomLeft_.x;
  frameRect.pos.y = frameRect.height / 2 + bottomLeft_.y;
  return frameRect;
}

void maslevtsov::Rectangle::move(point_t pnt) noexcept
{
  double movedX = pnt.x - getFrameRect().pos.x;
  double movedY = pnt.y - getFrameRect().pos.y;
  bottomLeft_.x += movedX;
  bottomLeft_.y += movedY;
  topRight_.x += movedX;
  topRight_.y += movedY;
}

void maslevtsov::Rectangle::move(double dx, double dy) noexcept
{
  bottomLeft_.x += dx;
  bottomLeft_.y += dy;
  topRight_.x += dx;
  topRight_.y += dy;
}

void maslevtsov::Rectangle::scale(double k) noexcept
{
  point_t frameCenter = getFrameRect().pos;
  bottomLeft_ = {
    frameCenter.x - (frameCenter.x - bottomLeft_.x) * k, frameCenter.y - (frameCenter.y - bottomLeft_.y) * k};
  topRight_ = {frameCenter.x + (topRight_.x - frameCenter.x) * k, frameCenter.y + (topRight_.y - frameCenter.y) * k};
}

maslevtsov::Rectangle* maslevtsov::makeRectangle(const double* arguments)
{
  Rectangle* rect = new Rectangle({arguments[0], arguments[1]}, {arguments[2], arguments[3]});
  return rect;
}
