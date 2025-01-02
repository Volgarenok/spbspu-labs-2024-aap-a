#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"
kiselev::Rectangle::Rectangle(kiselev::point_t leftDown, kiselev::point_t rightUp) :
  leftDown_(leftDown),
  rightUp_(rightUp)
{
  if (leftDown.x >= rightUp.x || leftDown.y >= rightUp.y)
  {
    throw std::invalid_argument("Incorrect parameters");
  }
}
double kiselev::Rectangle::getArea() const noexcept
{
  double area = (rightUp_.x - leftDown_.x) * (rightUp_.y - leftDown_.y);
  return area;
}
kiselev::rectangle_t kiselev::Rectangle::getFrameRect() const noexcept
{
  double centreForX = leftDown_.x + (rightUp_.x - leftDown_.x) / 2;
  double centreForY = leftDown_.y + (rightUp_.y - leftDown_.y) / 2;
  return { rightUp_.x - leftDown_.x, rightUp_.y - leftDown_.y, { centreForX, centreForY } };
}
void kiselev::Rectangle::move(point_t a) noexcept
{
  point_t centre = this->getFrameRect().pos;
  double moveX = a.x - centre.x;
  double moveY = a.y - centre.y;
  leftDown_.x += moveX;
  leftDown_.y += moveY;
  rightUp_.x += moveX;
  rightUp_.y += moveY;
}
void kiselev::Rectangle::move(double dx, double dy) noexcept
{
  leftDown_.x += dx;
  leftDown_.y += dy;
  rightUp_.x += dx;
  rightUp_.y += dy;
}
void kiselev::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect coefficient");
  }
  point_t centre = this->getFrameRect().pos;
  leftDown_.x = centre.x + (leftDown_.x - centre.x) * k;
  leftDown_.y = centre.y + (leftDown_.y - centre.y) * k;
  rightUp_.x = centre.x + (rightUp_.x - centre.x) * k;
  rightUp_.y = centre.y + (rightUp_.y - centre.y) * k;
}
