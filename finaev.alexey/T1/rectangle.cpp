#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

finaev::Rectangle::Rectangle(point_t l, point_t r):
  leftDown(l),
  rightUp(r)
{
  if (x0 >= x1 || y0 >= y1)
  {
    throw std::invalid_argument("Uncorrect argument");
  }
}

double finaev::Rectangle::getArea() const
{
  return (rightUp.x - leftDown.x) * (rightUp.y - leftDown.y);
}

finaev::rectangle_t finaev::Rectangle::getFrameRect() const
{
  double x = leftDown.x + (rightUp.x - leftDown.x) / 2;
  double y = leftDown.y + (rightUp.y - leftDown.y) / 2;
  point_t b = {x, y};
  rectangle_t a = {pos, width, height};
  point_t pos = b;
  double width = rightUp.x - leftDown.x;
  double height = rightUp.y - leftDown.y;
  rectangle_t a = {pos, width, height};
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
