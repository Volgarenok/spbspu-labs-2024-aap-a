#include "ring.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Ring::Ring(point_t pos, double radi, double rado):
  center(pos),
  innerradius(radi),
  outerradius(rado)
{}

double asafov::Ring::getArea() const
{
  return M_PI * (outerradius * outerradius - innerradius * innerradius);
}

rectangle_t asafov::Ring::getFrameRect() const
{
  rectangle_t rect;
  rect.height = outerradius * 2.0;
  rect.width = outerradius * 2.0;
  rect.pos = center;
  return rect;
}

void asafov::Ring::move(double x, double y)
{
  center.x += x;
  center.y += y;
}

void asafov::Ring::move(point_t pos)
{
  center = pos;
}

void asafov::Ring::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  center.x += (center.x - rect.pos.x) * (scale - 1);
  center.y += (center.y - rect.pos.y) * (scale - 1);
  innerradius *= scale;
  outerradius *= scale;
}
