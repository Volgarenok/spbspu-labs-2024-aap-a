#include "square.hpp"
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Square::Square(point_t a, double s):
lb(a), side(s)
{}

double asafov::Square::getArea() const
{
  return side * side;
}

rectangle_t asafov::Square::getFrameRect() const
{
  rectangle_t frect;
  frect.height = side;
  frect.width = side;
  frect.pos.x = lb.x + side / 2;
  frect.pos.y = lb.y + side / 2;
  return frect;
}

void asafov::Square::move(double x, double y)
{
  lb.x += x;
  lb.y += y;
}

void asafov::Square::move(point_t pos)
{
  double temp = pos.x - (lb.x + (side / 2.0));
  lb.x += temp;
  temp = pos.y - (lb.y + (side / 2.0));
  lb.y += temp;
}

void asafov::Square::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  lb.x += (lb.x - rect.pos.x) * (scale - 1);
  lb.y += (lb.y - rect.pos.y) * (scale - 1);
  side *= scale;
}
