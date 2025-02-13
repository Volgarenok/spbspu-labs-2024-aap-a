#include "rectangle.hpp"
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Rectangle::Rectangle(point_t a, point_t b):
  lb(a),
  rt(b)
{}

double asafov::Rectangle::getArea() const
{
  return std::pow((lb.x - rt.x) * (lb.x - rt.x), 0.5) * std::pow((lb.y - rt.y) * (lb.y - rt.y), 0.5);
}

rectangle_t asafov::Rectangle::getFrameRect() const
{
  rectangle_t rect;
  rect.height = rt.y - lb.y;
  rect.width = rt.x - lb.x;
  rect.pos.x = lb.x + (rt.x - lb.x) / 2.0;
  rect.pos.y = lb.y + (rt.y - lb.y) / 2.0;
  return rect;
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
  rectangle_t rect = getFrameRect();
  lb.x += pos.x - rect.pos.x;
  rt.x += pos.x - rect.pos.x;
  lb.y += pos.y - rect.pos.y;
  rt.y += pos.y - rect.pos.y;
}

void asafov::Rectangle::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  rt.x += (rt.x - rect.pos.x) * (scale - 1.0);
  rt.y += (rt.y - rect.pos.y) * (scale - 1.0);
  lb.x += (lb.x - rect.pos.x) * (scale - 1.0);
  lb.y += (lb.y - rect.pos.y) * (scale - 1.0);
}
