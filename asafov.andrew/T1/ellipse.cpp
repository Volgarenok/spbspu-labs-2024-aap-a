#include "ellipse.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

asafov::Ellipse::Ellipse(point_t pos, double radv, double radh):
center(pos), radiusv(radv), radiush(radh)
{
  
}

double asafov::Ellipse::getArea() const
{
  return M_PI * radiusv * radiush;
}

rectangle_t asafov::Ellipse::getFrameRect() const
{
  rectangle_t frect;
  frect.height = radiusv * 2;
  frect.width = radiush * 2;
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

void asafov::Ellipse::scale(point_t pos, double scale)
{
  center.x += (center.x - pos.x) * (scale - 1);
  center.y += (center.y - pos.y) * (scale - 1);
  radiusv *= scale;
  radiush *= scale;
}
