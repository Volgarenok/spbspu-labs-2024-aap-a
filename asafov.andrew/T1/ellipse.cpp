#include "ellipse.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Ellipse::Ellipse(point_t pos, double radv, double radh):
  center(pos),
  radiusv(radv),
  radiush(radh)
{}

double asafov::Ellipse::getArea() const
{
  return M_PI * radiusv * radiush;
}

rectangle_t asafov::Ellipse::getFrameRect() const
{
  rectangle_t frect;
  frect.height = radiusv * 2.0;
  frect.width = radiush * 2.0;
  frect.pos = center;
  return frect;
}

void asafov::Ellipse::move(double x, double y)
{
  center.x += x;
  center.y += y;
}

void asafov::Ellipse::move(point_t pos)
{
  center = pos;
}

void asafov::Ellipse::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  center.x += (center.x - rect.pos.x) * (scale - 1);
  center.y += (center.y - rect.pos.y) * (scale - 1);
  radiusv *= scale;
  radiush *= scale;
}
