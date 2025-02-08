#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Circle::Circle(point_t pos, double rad):
  center(pos),
  radius(rad)
{}

double asafov::Circle::getArea() const
{
  return radius * radius * M_PI;
}

rectangle_t asafov::Circle::getFrameRect() const
{
  rectangle_t frect;
  frect.pos = center;
  frect.height = 2.0 * radius;
  frect.width = 2.0 * radius;
  return frect;
}

void asafov::Circle::move(double x, double y)
{
  center.x += x;
  center.y += y;
}

void asafov::Circle::move(point_t pos)
{
  center = pos;
}

void asafov::Circle::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  center.x += (center.x - rect.pos.x) * (scale - 1);
  center.y += (center.y - rect.pos.y) * (scale - 1);
  radius *= scale;
}
