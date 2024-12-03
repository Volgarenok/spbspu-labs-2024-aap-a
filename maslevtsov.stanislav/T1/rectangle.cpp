#include "rectangle.hpp"

maslevtsov::Rectangle::Rectangle(point_t bottomLeft, point_t topRight):
  bottomLeft_(bottomLeft),
  topRight_(topRight)
{}

double maslevtsov::Rectangle::getArea() const
{
  return (topRight_.x - bottomLeft_.x) * (topRight_.y - bottomLeft_.y);
}

maslevtsov::rectangle_t maslevtsov::Rectangle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width = topRight_.x - bottomLeft_.x;
  frameRect.height = topRight_.y - bottomLeft_.y;
  frameRect.pos.x = frameRect.width / 2 + bottomLeft_.x;
  frameRect.pos.y = frameRect.height / 2 + bottomLeft_.y;
  return frameRect;
}

void maslevtsov::Rectangle::move(point_t pnt)
{
  double movedX = getFrameRect().pos.x - pnt.x;
  double movedY = getFrameRect().pos.y - pnt.y;
  bottomLeft_.x += movedX;
  bottomLeft_.y += movedY;
  topRight_.x += movedX;
  topRight_.y += movedY;
}

void maslevtsov::Rectangle::move(double dx, double dy)
{
  bottomLeft_.x += dx;
  bottomLeft_.y += dy;
  topRight_.x += dx;
  topRight_.y += dy;
}

void maslevtsov::Rectangle::scale(double k)
{
  double scaledX = (getFrameRect().pos.x - bottomLeft_.x) * k - (getFrameRect().pos.x - bottomLeft_.x);
  double scaledY = (getFrameRect().pos.y - bottomLeft_.y) * k - (getFrameRect().pos.y - bottomLeft_.y);
  bottomLeft_.x -= scaledX;
  bottomLeft_.y += scaledY;
  topRight_.x -= scaledX;
  topRight_.y += scaledY;
}
