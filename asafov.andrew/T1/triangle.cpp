#include "triangle.hpp"
#include <algorithm>
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Triangle::Triangle(point_t a, point_t b, point_t c):
one(a), two(b), three(c)
{}

double asafov::Triangle::getArea() const
{
  double sidea = pow(pow((one.x - two.x), 2.0) + pow((one.y - two.y), 2.0), 0.5);
  double sideb = pow(pow((two.x - three.x), 2.0) + pow((two.y - three.y), 2.0), 0.5);
  double sidec = pow(pow((one.x - three.x), 2.0) + pow((one.y - three.y), 2.0), 0.5);
  return pow(((sidea + sideb + sidec) * (sidea + sideb - sidec) * (sidea - sideb + sidec) * (sideb + sidec - sidea) / 16), 0.5);
}

rectangle_t asafov::Triangle::getFrameRect() const
{
  rectangle_t frect;
  frect.height = std::max({one.y, two.y, three.y}) - std::min({one.y, two.y, three.y});
  frect.width = std::max({one.x, two.x, three.x}) - std::min({one.x, two.x, three.x});
  frect.pos.x = std::min({one.x, two.x, three.x}) + frect.width / 2;
  frect.pos.y = std::min({one.y, two.y, three.y}) + frect.height / 2;
  return frect;
}

void asafov::Triangle::move(double x, double y)
{
  one.x += x;
  one.y += y;
  two.x += x;
  two.y += y;
  three.x += x;
  three.y += y;
}

void asafov::Triangle::move(point_t pos)
{
  rectangle_t frect = getFrameRect();
  one.x += pos.x - frect.pos.x;
  one.y += pos.y - frect.pos.y;
  two.x += pos.x - frect.pos.x;
  two.y += pos.y - frect.pos.y;
  three.x += pos.x - frect.pos.x;
  three.y += pos.y - frect.pos.y;
}

void asafov::Triangle::scale(point_t pos, double scale)
{
  one.x += (one.x - pos.x) * (scale - 1);
  one.y += (one.y - pos.y) * (scale - 1);
  two.x += (two.x - pos.x) * (scale - 1);
  two.y += (two.y - pos.y) * (scale - 1);
  three.x += (three.x - pos.x) * (scale - 1);
  three.y += (three.y - pos.y) * (scale - 1);
}
