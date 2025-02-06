#include "rectangle.hpp"
#include <stdexcept>
kiselev::Rectangle::Rectangle(point_t leftDown, point_t rightUp):
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
  const double centreForX = leftDown_.x + (rightUp_.x - leftDown_.x) / 2;
  const double centreForY = leftDown_.y + (rightUp_.y - leftDown_.y) / 2;
  return { rightUp_.x - leftDown_.x, rightUp_.y - leftDown_.y, { centreForX, centreForY } };
}
void kiselev::Rectangle::move(point_t a)
{
  const point_t centre = getFrameRect().pos;
  const double moveX = a.x - centre.x;
  const double moveY = a.y - centre.y;
  move(moveX, moveY);
}
void kiselev::Rectangle::move(double dx, double dy)
{
  leftDown_ = movePoint(leftDown_, dx, dy);
  rightUp_ = movePoint(rightUp_, dx, dy);
}
void kiselev::Rectangle::scale(double k)
{
  const point_t centre = getFrameRect().pos;
  leftDown_ = scalePoint(leftDown_, centre, k);
  rightUp_ = scalePoint(rightUp_, centre, k);
}
kiselev::Shape* kiselev::Rectangle::clone() const
{
  return new Rectangle(*this);
}
