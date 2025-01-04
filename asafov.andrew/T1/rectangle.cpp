#include "rectangle.hpp"
#include <cmath>

asafov::Rectangle::Rectangle(point_t a, point_t b):
lb(a), rt(b)
{}

double asafov::Rectangle::getArea() const
{
  return abs((lb.x - rt.x) * (lb.y - rt.y));
}

rectangle_t asafov::Rectangle::getFrameRect() const
{
  rectangle_t frect;
  frect.height = abs(lb.y - rt.y);
  frect.width = abs(lb.x - rt.x);
  frect.pos.x = abs(lb.x + rt.x) / 2;
  frect.pos.y = abs(lb.y + rt.y) / 2;
  return frect;
}

void asafov::Rectangle::move(double x, double y)
{
  lb.x += x;
  rt.x += x;
  lb.y += y;
  rt.y += y;
}

void asafov::Rectangle::move(point_t pos)
{
  double temp = abs(lb.x + rt.x) / 2 - pos.x;
  lb.x += temp;
  rt.x += temp;
  temp = abs(lb.y + rt.y) / 2 - pos.y;
  lb.y += temp;
  rt.y += temp;
}

void asafov::Rectangle::scale(point_t pos, double scale)
{
  rt.x += (rt.x - pos.x) * (scale - 1.0);
  rt.y += (rt.y - pos.y) * (scale - 1.0);
  lb.x += (lb.x - pos.x) * (scale - 1.0);
  lb.y += (lb.y - pos.y) * (scale - 1.0);
}
