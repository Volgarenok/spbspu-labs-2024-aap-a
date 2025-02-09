#include "rectangle.hpp"
#include <stdexcept>

maslevtsov::Rectangle::Rectangle(point_t bottomLeft, point_t topRight):
  bottomLeft_(bottomLeft),
  topRight_(topRight)
{
  if (topRight.x <= bottomLeft.x || topRight.y <= bottomLeft.y)
  {
    throw std::logic_error("incorrect coordinates");
  }
}

double maslevtsov::Rectangle::getArea() const noexcept
{
  return (topRight_.x - bottomLeft_.x) * (topRight_.y - bottomLeft_.y);
}

maslevtsov::rectangle_t maslevtsov::Rectangle::getFrameRect() const noexcept
{
  rectangle_t frameRect = {0, 0, {0, 0}};
  frameRect.width = topRight_.x - bottomLeft_.x;
  frameRect.height = topRight_.y - bottomLeft_.y;
  frameRect.pos = {frameRect.width / 2 + bottomLeft_.x, frameRect.height / 2 + bottomLeft_.y};
  return frameRect;
}

void maslevtsov::Rectangle::move(point_t pnt) noexcept
{
  double movedX = pnt.x - getFrameRect().pos.x;
  double movedY = pnt.y - getFrameRect().pos.y;
  bottomLeft_ = {bottomLeft_.x + movedX, bottomLeft_.y + movedY};
  topRight_ = {topRight_.x + movedX, topRight_.y + movedY};
}

void maslevtsov::Rectangle::move(double dx, double dy) noexcept
{
  bottomLeft_ = {bottomLeft_.x + dx, bottomLeft_.y + dy};
  topRight_ = {topRight_.x + dx, topRight_.y + dy};
}

void maslevtsov::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("invalid coefficient");
  }
  unsafeScale(k);
}

void maslevtsov::Rectangle::unsafeScale(double k) noexcept
{
  point_t frameCenter = getFrameRect().pos;
  double leftDiffX = (frameCenter.x - bottomLeft_.x) * k;
  double leftDiffY = (frameCenter.y - bottomLeft_.y) * k;
  double rightDiffX = (topRight_.x - frameCenter.x) * k;
  double rightDiffY = (topRight_.y - frameCenter.y) * k;
  bottomLeft_ = {frameCenter.x - leftDiffX, frameCenter.y - leftDiffY};
  topRight_ = {frameCenter.x + rightDiffX, frameCenter.y + rightDiffY};
}
