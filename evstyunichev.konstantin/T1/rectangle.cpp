#include "rectangle.hpp"
#include <iostream>
#include "base-types.hpp"

evstyunichev::Rectangle::Rectangle(point_t leftDown, point_t rightUp):
  leftDown_(leftDown), rightUp_(rightUp)
{
}

double evstyunichev::Rectangle::getArea()
{
  return (rightUp_.x - leftDown_.x) * (rightUp_.y - leftDown_.y);
}

evstyunichev::rectangle_t evstyunichev::Rectangle::getFrameRect()
{
  rectangle_t frame;
  frame.pos = find_mid();
  frame.height = rightUp_.y - leftDown_.y;
  frame.width = rightUp_.x - leftDown_.x;
  return frame;
}

void evstyunichev::Rectangle::move(double dx, double dy)
{
  leftDown_.x += dx;
  leftDown_.y += dy;
  rightUp_.x += dx;
  rightUp_.y += dy;
  return;
}

void evstyunichev::Rectangle::move(point_t cds)
{
  point_t mid = find_mid();
  move(cds.x - mid.x, cds.y - mid.y);
  return;
}

evstyunichev::point_t evstyunichev::Rectangle::find_mid()
{
  point_t mid{};
  mid.x = (rightUp_.x - leftDown_.x) / 2.0;
  mid.y = (rightUp_.y - leftDown_.y) / 2.0;
  return mid;
}

void evstyunichev::Rectangle::scale(double k)
{
  point_t mid = find_mid();
  double w = (rightUp_.x - leftDown_.x) * k, h = (rightUp_.y - leftDown_.y) * k;
  leftDown_.x = mid.x - w / 2.0;
  rightUp_.x = mid.x + w / 2.0;
  leftDown_.y = mid.y - h / 2.0;
  rightUp_.y = mid.y + h / 2.0;
  return;
}
