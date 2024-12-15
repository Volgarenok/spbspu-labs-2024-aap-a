#include "rectangle.hpp"
#include <stdexcept>

finaev::Rectangle::Rectangle(point_t l, point_t r) :
  leftDown(l), rightUp(r)
{
}
double finaev::Rectangle::getArea() const
{
  return (rightUp.x - leftDown.x) * (rightUp.y - leftDown.y);
}
finaev::rectangle_t finaev::Rectangle::getFrameRect() const
{
  point_t b;
  b.x = leftDown.x + (rightUp.x - leftDown.x) / 2;
  b.y = leftDown.y + (rightUp.y - leftDown.y) / 2;
  rectangle_t a;
  a.pos = b;
  a.wedth = rightUp.x - leftDown.x;
  a.height = rightUp.y - leftDown.y;
  return a;
}
void finaev::Rectangle::move(point_t a)
{
  point_t t;
  t = getFrameRect().pos;
  leftDown.x += (a.x - t.x);
  leftDown.y += (a.y - t.y);
  rightUp.x += (a.x - t.x);
  rightUp.y += (a.y - t.y);
}
void finaev::Rectangle::move(double sx, double sy)
{
  leftDown.x += sx;
  leftDown.y += sy;
  rightUp.x += sx;
  rightUp.y += sy;
}
void finaev::Rectangle::scale(double k)
{
  point_t centre = getFrameRect().pos;
  leftDown.x = (leftDown.x - centre.x) * k + centre.x;
  rightUp.x = (rightUp.x - centre.x) * k + centre.x;
  leftDown.y = (leftDown.y - centre.y) * k + centre.y;
  rightUp.y = (rightUp.y - centre.y) * k + centre.y;
}
