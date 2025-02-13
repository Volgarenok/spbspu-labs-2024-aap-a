#include "square.hpp"
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Square::Square(point_t a, double s):
  lb(a),
  side(s)
{}

double asafov::Square::getArea() const
{
  return side * side;
}

rectangle_t asafov::Square::getFrameRect() const
{
  rectangle_t rect;
  rect.height = side;
  rect.width = side;
  rect.pos.x = lb.x + side / 2.0;
  rect.pos.y = lb.y + side / 2.0;
  return rect;
}

void asafov::Square::move(double x, double y)
{
  lb.x += x;
  lb.y += y;
}

void asafov::Square::move(point_t pos)
{
  lb.x += pos.x - (lb.x + (side / 2.0));
  lb.y += pos.y - (lb.y + (side / 2.0));
}

void asafov::Square::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  lb.x += (lb.x - rect.pos.x) * (scale - 1.0);
  lb.y += (lb.y - rect.pos.y) * (scale - 1.0);
  side *= scale;
}
