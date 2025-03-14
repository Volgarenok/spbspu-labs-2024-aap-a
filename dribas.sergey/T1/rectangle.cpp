#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>
#include <stdlib.h>

namespace
{
  dribas::point_t getPoint(dribas::point_t center, dribas::point_t angle, double ratio)
  {
    return { center.x + (angle.x - center.x) * ratio, center.y + (angle.y - center.y) * ratio };
  }
}

dribas::Rectangle::Rectangle(point_t leftDown, point_t rightUp):
  leftDown_(leftDown),
  rightUp_(rightUp)
{
  if (!(leftDown.x < rightUp.x && leftDown.y < rightUp.y)) {
    throw std::invalid_argument("error with rectangle size");
  }
}

double dribas::Rectangle::getArea() const
{
  double weight = rightUp_.x - leftDown_.x;
  double hieght = rightUp_.y - leftDown_.y;
  return weight * hieght;
}

dribas::rectangle_t dribas::Rectangle::getFrameRect() const
{
  double height = rightUp_.y - leftDown_.y;
  double width = rightUp_.x - leftDown_.x;
  double posX = leftDown_.x + (width / 2.0L);
  double posY = leftDown_.y + (height / 2.0L);
  return rectangle_t{ { width }, { height }, { { posX }, { posY } } };
}

void dribas::Rectangle::move(double x, double y)
{
  leftDown_.x += x;
  leftDown_.y += y;
  rightUp_.x += x;
  rightUp_.y += y;
}

void dribas::Rectangle::move(point_t centerP)
{
  point_t pos = getFrameRect().pos;
  double moveX = centerP.x - pos.x;
  double moveY = centerP.y - pos.y;
  move(moveX, moveY);
}

void dribas::Rectangle::scaleSilent(double ratio)
{
  rectangle_t fremRect = getFrameRect();
  point_t pos = fremRect.pos;
  rightUp_ = getPoint(pos, rightUp_, ratio);
  leftDown_ = getPoint(pos, leftDown_, ratio);
}

dribas::Shape* dribas::Rectangle::clone() const
{
  return new Rectangle(*this);
}
