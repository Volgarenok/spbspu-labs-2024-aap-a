#include "rectangle.h"
#include <stdexcept>

finaev::Rectangle::Rectangle(point_t l, point_t r) :
  leftDown(l), rightUp(r)
{
  if (l.x >= r.x || l.y >= r.y)
  {
    throw std::invalid_argument("Invalid argument!");
  }
}
double finaev::Rectangle::getArea()
{
  return (rightUp.x - leftDown.x) * (rightUp.y - leftDown.y);
}
finaev::point_t finaev::Rectangle::getCentre()
{
  point_t a;
  a.x = leftDown.x + (rightUp.x - leftDown.x) / 2;
  a.y = leftDown.y + (rightUp.y - leftDown.y) / 2;
  return a;
}
finaev::rectangle_t finaev::Rectangle::getFrameRect()
{
  rectangle_t a;
  a.pos = getCentre();
  a.wedth = rightUp.x - leftDown.x;
  a.height = rightUp.y - leftDown.y;
  return a;
}
void finaev::Rectangle::move(point_t a)
{
  point_t t;
  t = getCentre();
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
  point_t centre = getCentre();
  leftDown.x = (leftDown.x - centre.x) * k + centre.x;
  rightUp.x = (rightUp.x - centre.x) * k + centre.x;
  leftDown.y = (leftDown.y - centre.y) * k + centre.y;
  rightUp.y = (rightUp.y - centre.y) * k + centre.y;
}
