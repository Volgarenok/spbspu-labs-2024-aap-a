#include "complexquad.hpp"
#include <algorithm>
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Complexquad::Complexquad(point_t a, point_t b, point_t c, point_t d) :
  one(a), two(b), three(c), four(d)
{}

double asafov::Complexquad::getArea() const
{
  point_t center = {};
  center.x = std::max({ one.x, two.x, three.x, four.x }) - std::min({ one.x, two.x, three.x, four.x });
  center.y = std::max({ one.y, two.y, three.y, four.y }) - std::min({ one.y, two.y, three.y, four.y });
  double sidea = pow(pow((one.x - four.x), 2.0) + pow((one.y - four.y), 2.0), 0.5);
  double sideb = pow(pow((four.x - center.x), 2.0) + pow((four.y - center.y), 2.0), 0.5);
  double sidec = pow(pow((one.x - center.x), 2.0) + pow((one.y - center.y), 2.0), 0.5);
  double semiarea = pow(((sidea + sideb + sidec) * (sidea + sideb - sidec) * (sidea - sideb + sidec) * (sideb + sidec - sidea) / 16), 0.5);
  sidea = pow(pow((two.x - three.x), 2.0) + pow((two.y - three.y), 2.0), 0.5);
  sideb = pow(pow((two.x - center.x), 2.0) + pow((two.y - center.y), 2.0), 0.5);
  sidec = pow(pow((three.x - center.x), 2.0) + pow((three.y - center.y), 2.0), 0.5);
  return semiarea + pow(((sidea + sideb + sidec) * (sidea + sideb - sidec) * (sidea - sideb + sidec) * (sideb + sidec - sidea) / 16), 0.5);
}

rectangle_t asafov::Complexquad::getFrameRect() const
{
  rectangle_t frect;
  frect.height = std::max({ one.y, two.y, three.y, four.y }) - std::min({ one.y, two.y, three.y, four.y });
  frect.width = std::max({ one.x, two.x, three.x, four.x }) - std::min({ one.x, two.x, three.x, four.x });
  frect.pos.x = std::min({ one.x, two.x, three.x, four.x }) + frect.width / 2;
  frect.pos.y = std::min({ one.y, two.y, three.y, four.x }) + frect.height / 2;
  return frect;
}

void asafov::Complexquad::move(double x, double y)
{
  one.x += x;
  one.y += y;
  two.x += x;
  two.y += y;
  three.x += x;
  three.y += y;
  four.x += x;
  four.y += y;
}

void asafov::Complexquad::move(point_t pos)
{
  point_t center = {};
  center.x = std::max({ one.x, two.x, three.x, four.x }) - std::min({ one.x, two.x, three.x, four.x });
  center.y = std::max({ one.y, two.y, three.y, four.y }) - std::min({ one.y, two.y, three.y, four.y });
  double temp = center.x - pos.x;
  one.x += temp;
  two.x += temp;
  three.x += temp;
  four.x += temp;
  temp = center.y - pos.y;
  one.y += temp;
  two.y += temp;
  three.y += temp;
  four.y += temp;
}

void asafov::Complexquad::scale(point_t pos, double scale)
{
  one.x += (one.x - pos.x) * (scale - 1);
  one.y += (one.y - pos.y) * (scale - 1);
  two.x += (two.x - pos.x) * (scale - 1);
  two.y += (two.y - pos.y) * (scale - 1);
  three.x += (three.x - pos.x) * (scale - 1);
  three.y += (three.y - pos.y) * (scale - 1);
  four.x += (four.x - pos.x) * (scale - 1);
  four.y += (four.y - pos.y) * (scale - 1);
}
