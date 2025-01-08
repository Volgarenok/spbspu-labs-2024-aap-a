#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"
kiselev::Rectangle::Rectangle(point_t leftDown, point_t rightUp) :
  leftDown_(leftDown),
  rightUp_(rightUp)
{
  if (leftDown.x >= rightUp.x || leftDown.y >= rightUp.y)
  {
    throw std::invalid_argument("Incorrect parameters");
  }
}
double kiselev::Rectangle::getArea() const
{
  return (rightUp_.x - leftDown_.x) * (rightUp_.y - leftDown_.y);
}
kiselev::rectangle_t kiselev::Rectangle::getFrameRect() const
{
  double centreForX = leftDown_.x + (rightUp_.x - leftDown_.x) / 2;
  double centreForY = leftDown_.y + (rightUp_.y - leftDown_.y) / 2;
  return { rightUp_.x - leftDown_.x, rightUp_.y - leftDown_.y, { centreForX, centreForY } };
}
void kiselev::Rectangle::move(point_t a)
{
  point_t centre = this->getFrameRect().pos;
  double moveX = a.x - centre.x;
  double moveY = a.y - centre.y;
  move(moveX, moveY);
}
void kiselev::Rectangle::move(double dx, double dy)
{
  leftDown_.x += dx;
  leftDown_.y += dy;
  rightUp_.x += dx;
  rightUp_.y += dy;
}
void kiselev::Rectangle::scale(double k)
{
  point_t centre = this->getFrameRect().pos;
  scalePoint(leftDown_, centre, k);
  scalePoint(rightUp_, centre, k);
}
